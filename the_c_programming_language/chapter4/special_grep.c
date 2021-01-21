#include <stdio.h>
#define MAXLINE 1000  // maximum input line length

int getline_(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";  // pattern to search for

// find all lines matching pattern
int main() {
  char line[MAXLINE];
  int found = 0;

  while (getline_(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }

  return 0;
}

// getline: get line into s, return length
int getline_(char s[], int lim) {
  int c, i;

  i = 0;
  while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

// strindex: return index of t in s, -1 if none
int strindex(char s[], char t[]) {
  int i, k;

  for (i = 0; s[i] != '\0'; ++i) {
    for (k = 0; t[k] != '\0' && t[k] == s[i + k]; ++k)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
