#include <stdio.h>

// shellsort: sort v[0]...v[n-1] into increasing order
void shellsort(int v[], int n);

int main() {
  int v[] = {18, 22, 34, 4, 5, 7, 2, 1};
  for (int i = 0; i < 8; ++i)
    printf("%d ", v[i]);
  shellsort(v, 8);
  printf("\n");
  for (int i = 0; i < 8; ++i)
    printf("%d ", v[i]);
  return 0;
}

void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
}
