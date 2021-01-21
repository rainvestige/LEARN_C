// Exercise 1-20. Write a program `detab` that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed set
// of tab stops, say every `n` columns. Should `n` be a variable or a symbolic
// parameter?
#include <stdio.h>

#define MAXLINE 1000

int getline_(char s[], int maxline);
void detab(char from[], char to[]);
int replace_tab(char s[], int len, int maxline, int nspace);
void copy(char from[], char to[]);
void print_line(char line[]);

int main() {
  int len;
  char line[MAXLINE];
  char detab_line[MAXLINE], tmp[MAXLINE];
  while ((len = getline_(line, MAXLINE)) > 0) {
    detab(line, detab_line);
    //printf("%s", detab_line);
    print_line(line);
    print_line(detab_line);
    copy(detab_line, tmp);
    //print_line(tmp);
    break;
  }
  return 0;
}

int getline_(char s[], int maxline) {
  int c, i;

  for (i = 0; i < maxline -1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void detab(char from[], char to[]) {
  int i, j;
  int maxline = MAXLINE;
  int tabstop = 8;

  j = 0;
  for (i = 0; from[i] != '\0'; ++i) {
    if (from[i] == '\t') {
      // replace tabs with spaces
      for (int k = 0; k < tabstop - j % tabstop && k + j < maxline; ++k)
        to[j+k] = ' ';
      j = j + tabstop - j % tabstop;
      // the following code doesn't work due to unknown reason
      //j = replace_tab(to, j, maxline, tabstop - j % tabstop);
      //++j;
    } else {
      to[j] = from[i];
      ++j;
    }
  }
  if (from[i] == '\0')
    to[j] = '\0';
}

int replace_tab(char s[], int index, int maxline, int nspace) {
  int i;

  for (i = 0; i < nspace && index + i < maxline; ++i) {
    s[index + i] = ' ';
  }

  if (index + i >= maxline) {
    // TODO
  }

  return index + i;
}

void copy(char from[], char to[]) {
  int i;

  for (i = 0; from[i] != '\0'; ++i) {
    to[i] = from[i];
  }
}

void print_line(char line[]) {
  int i;

  for (i = 0; line[i] != '\n'; ++i) {
    if (line[i] == '\t') {
      putchar('|');
    } else if (line[i] == ' ') {
      putchar('_');
    } else
      putchar(line[i]);
  }
  putchar('\n');
}
