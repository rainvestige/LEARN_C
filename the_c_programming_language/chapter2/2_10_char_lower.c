// Exercise 2-10. Rewrite the function `lower`, which converts upper case
// letters to lower case, with a conditional expression instead of if-else.
#include <stdio.h>

char lower(char c);

int main() {
  char c;
  int i = 0;

  while ((c = getchar()) != EOF)
    if (c >= 'A' && c <= 'Z')
      printf("%c is the lower case of %c\n", lower(c), c);

  return 0;
}

// assume character `c` is a letter, either upper case or lower case
char lower(char c) {
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
