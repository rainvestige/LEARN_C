#include <stdio.h>

#define MAXLINE 1000

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;  // current line length
  int max;  // maximum length seen so far
  char line[MAXLINE];
  char longest[MAXLINE];
  char tmp[MAXLINE];

  max = 0;
  while ((len = getline_(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      printf("\nlength of current line: %d\n", len-1);
      copy(longest, line);
    }
    // Exercise 1-17. print all lines that are longer than 80 characters.
    if (len - 1 > 80) {
      copy(tmp, line);
      printf("%s", tmp);
    }
  }
  if (max > 0)
    printf("%s", longest);

  return 0;
}

// getline_: read a line into line, return length
int getline_(char line[], int maxline) {
  int c, i;

  // `maxline-1` retain the '\n' at the end of the line
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';  // c language use '\0' to mark the end of string.
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
