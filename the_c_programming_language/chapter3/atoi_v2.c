#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

// atoi: convert s to integer; version 2
int atoi(char s[]);
int getline_(char s[], int maxline);

int main() {
  char s[MAXLINE];

  while(getline_(s, MAXLINE) > 0) {
    printf("%d\n", atoi(s));
  }
  return 0;
}

int atoi(char s[]) {
  int i, n, sign;
  // skip leading white space
  for (i = 0; isspace(s[i]); ++i)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  // skip sign
  if (s[i] == '+' || s[i] == '-')
    ++i;
  for (n = 0; isdigit(s[i]); ++i)
    n = 10 * n + (s[i] - '0');

  return sign * n;
}

int getline_(char s[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}
