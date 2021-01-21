#include <stdio.h>

int my_strlen(char s[]);


int main() {
  int len;

  len = my_strlen("hello, world!");
  printf("the length of the string: %d\n", len);

  return 0;
}

int my_strlen(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  return i;
}
