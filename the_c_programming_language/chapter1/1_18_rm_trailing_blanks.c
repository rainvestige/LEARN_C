// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.
#include <stdio.h>

#define MAXLINE 1000

int getline_(char line[], int maxline);
void copy(char to[], char from[]);
void rm_line_trailing_blanks(char s[], int len);
int rm_entirely_blank_lines(char s[], int maxline);
int rm_text_trailing_blanks(char from[], char to[]);


int main() {
  char line[MAXLINE];
  char tmp[MAXLINE];
  int len;

  len = rm_entirely_blank_lines(line, MAXLINE);
  printf("\nLength of text stream: %d\n%s", len, line);

  len = rm_text_trailing_blanks(line, tmp);
  printf("\nLength of text stream: %d\n%s", len, line);


  return 0;
}

int getline_(char line[], int maxline) {
  int i;
  int c;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

// copy: copy `from` into `to`; assume `to` is big enough
void copy(char to[], char from[]) {
  //for (int i = 0; i < MAXLINE; ++i) {
  //  if (from[i] != '\0')
  //    to[i] = from[i];
  //  else
  //    break;
  //}
  int i;

  i = 0;
  while (from[i] != '\0') {
    to[i] = from[i];
    ++i;
  }
}

void rm_line_trailing_blanks(char s[], int len) {
  if (s[len-1] == '\n') {
    --len;
    while (s[len-1] == ' ' || s[len-1] == '\t') {
      --len;
    }
    s[len] = '\n';
    s[len+1] = '\0';
  }
}

// remove the entirely blank lines from the text stream.
// return the length of the text stream.
int rm_entirely_blank_lines(char s[], int maxline) {
  int c, i;
  i = 0;

  while ((c = getchar()) != EOF && i < maxline) {
    if (i > 0 && s[i-1] == '\n' && c == '\n')
      ;
    else if (i == 0 && c == '\n')
      ;  // blank line at the beginning
    else {
      s[i] = c;
      ++i;
    }
  }
  s[i] = EOF;
  return i;
}

// return the length of the `to`
int rm_text_trailing_blanks(char from[], char to[]) {
  int i, j;
  i = j = 0;

  while (from[i] != EOF) {
    if (from[i] == '\n') {
      // move backward to see if there are any blanks or tabs
      int k = 1;
      // the entirely blank lines are removed, so `i-k` is always valid
      while (from[i-k] == ' ' || from[i-k] == '\t') {
        --j;
        ++k;
      }
      to[j] = '\n';
      ++j;
      ++i;
    } else {
      to[j] = from[i];
      ++i;
      ++j;
    }
  }
  return j;
}
