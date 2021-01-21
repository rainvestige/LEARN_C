#include <stdio.h>

#define N 7

int main() {
  int a[N] = {0, 1, 2, 3, 4, 5, 6};
  for (int i = 0; i < N; ++i)
    printf("%6d%c", a[i], (i % 2 == 1 || i == N - 1) ? '\n' : ' ');
  int n = 1;
  printf("You have %d item%s.\n", n, (n == 1) ? "" : "s");
  return 0;
}
