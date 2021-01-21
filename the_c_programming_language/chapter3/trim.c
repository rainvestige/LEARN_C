#include <stdio.h>
#include <string.h>

// trim: remove trailing blanks, tabs, newlines
int trim(char s[]);

int main() {
  char s[] = "foo, bar.   \n";
  printf("string length: %lu, %s\n", strlen(s), s);
  trim(s);
  printf("string length: %zd, %s\n", strlen(s), s);
  return 0;
}

int trim(char s[]) {
  int n;

  for (n = strlen(s) - 1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  s[n + 1] = '\0';
  return n;
}
