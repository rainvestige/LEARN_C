// Exercise 4-1. Write the function `strindex(s, t)` which returns the position
// of the rightmost occurrence of `t` in `s`, or -1 if there is none.
#include <stdio.h>

#define MAXLINE 1000

int getline_(char s[], int limit);
// return the position of the rightmost occurrence of `t` in `s`
int strindex(char s[], char t[]);

int main() {
  int pos, found;
  char s[MAXLINE];
  char t[] = ".c";

  found = 0;
  while (getline_(s, MAXLINE) > 0) {
    if ((pos = strindex(s, t)) > 0) {
      printf("rightmost occurrence at %d\t%s", pos, s);
      found++;
    }
  }
  return 0;
}

int getline_(char s[], int limit) {
  int i, c;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int strindex(char s[], char t[]) {
  int i, j;
  int position;

  // default not found
  position = -1;
  for (i = 0; s[i] != '\0'; ++i) {
    for (j = 0; t[j] != '\0' && s[i+j] == t[j]; ++j)
      ;
    if (t[j] == '\0')
      // record the position have seen
      position = i;
  }
  return position;
}
