// Exercise 1-21. Write a program `entab` that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the same
// tab stops as for `detab`. When either a tab or a single blank would suffice
// to reach a tab stop, which should be given preference?
#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 8

int getline_(char s[], int maxline);
void entab(char from[], char to[]);
void print_line(char line[]);

int main() {
  char line[MAXLINE];
  char entab_line[MAXLINE];
  int len;

  while ((len = getline_(line, MAXLINE)) > 0) {
    entab(line, entab_line);
    print_line(line);
    print_line(entab_line);
  }

  return 0;
}

int getline_(char s[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void entab(char from[], char to[]) {
  int i, j, k, len;
  int tabstop = TABSTOP;

  j = k = len = 0;
  for (i = 0; from[i] != '\0'; ++i) {
    if (from[i] == '\t') {
      to[j] = from[i];
      ++j;
      len += tabstop - len % tabstop;
    } else if (from[i] == ' ') {
      // how many contiguous spaces
      for (k = 0; k < tabstop - len % tabstop && from[i+k] == ' '; ++k)
        continue;
      // contiguous spaces are greater than or equal to spaces to next tabstop
      if (k == tabstop - len % tabstop) {
        to[j] = '\t';
        i += k - 1;  // skip the contiguous spaces
        len += k;
      } else {
        to[j] = from[i];
        ++len;
      }

      ++j;
    } else {
      to[j] = from[i];
      ++j;
      ++len;
    }
  }
}

void print_line(char line[]) {
  int i;

  for (i = 0; line[i] != '\n'; ++i) {
    if (line[i] == '\t') {
      putchar('\\');
      putchar('t');
    } else if (line[i] == ' ') {
      putchar('_');
    } else
      putchar(line[i]);
  }
  putchar('\n');
}
