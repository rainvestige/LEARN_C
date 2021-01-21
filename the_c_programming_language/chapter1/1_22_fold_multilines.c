// Exercise 1-22. Write a program to "fold" long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.
#include <stdio.h>

#define MAXLINE 1000

// return the number of lines
int get_text_stream(char s[], int maxline);
void fold(char from[], char to[], int nline_from, int nline_to);
void print_text_stream(char s[]);

int main() {
  char text_str[MAXLINE];
  char fold_str[MAXLINE];
  int nline_from, nline_folded;

  nline_folded = 2;
  while ((nline_from = get_text_stream(text_str, MAXLINE)) > 0) {
    fold(text_str, fold_str, nline_from, nline_folded);
    print_text_stream(fold_str);
  }
  return 0;
}

int get_text_stream(char s[], int maxline) {
  int c, nline, i;

  nline = 0;
  for (i = 0; (c = getchar()) != EOF && i < maxline -1; ++i) {
    s[i] = c;
    if (c == '\n')
      nline++;
  }
  if (c == EOF)
    s[i] = EOF;
  if (i == maxline -1)
    s[i] = EOF;
  ++nline;  // view the EOF as special newline character
  return nline;
}

void fold(char from[], char to[], int nline_from, int nline_to) {
  if (nline_from <= nline_to) {
    printf("no need to fold");
    return ;
  }

  int COLUMN_N = 40;
  int nchar_line, i, current_nline, j;

  j = nchar_line = 0;
  current_nline = 1;
  for (i = 0; from[i] != EOF && current_nline <= nline_to; ++i) {
    if (from[i] == '\n') {
      ++current_nline;
      nchar_line = 0;
    }
    if (current_nline < nline_to) {
      to[j] = from[i];
      ++j;
      ++nchar_line;
    } else if (current_nline == nline_to && nchar_line < COLUMN_N) {
      to[j] = from[i];
      ++j;
      ++nchar_line;
    } else if (nchar_line < COLUMN_N + 3){
      to[j] = '.';
      ++j;
      ++nchar_line;
    } else {
      to[j] = EOF;
      break;
    }
  }
}

void print_text_stream(char s[]) {
  int i;

  for (i = 0; s[i] != EOF; ++i) {
    putchar(s[i]);
  }
  putchar('\n');
}
