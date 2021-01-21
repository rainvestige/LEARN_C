#include <stdio.h>

// count digits, whitespaces and others
int main() {
  int c, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (int i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      ++nwhite;
    } else if (c >= '0' && c <= '9') {
      ++ndigit[c-'0'];
    } else {
      ++nother;
    }
  }
  printf("digits = ");
  for (int i = 0; i < 10; ++i) {
    printf(" %d", ndigit[i]);
  }
  printf(", white space = %d, other = %d\n", nwhite, nother);
  return 0;
}
