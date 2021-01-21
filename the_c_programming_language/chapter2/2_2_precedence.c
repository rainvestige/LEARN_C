#include <stdio.h>

int main() {
  int c, lim;
  lim = 1000;
  char s[lim];

  for (int i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) != EOF)
      if (c != '\n')
        s[i] = c;
      else
        break;
    else
      break;
  }

  printf("%s\n", s);
  return 0;
}
