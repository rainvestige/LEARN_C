// Exercise 3-1. Our binary search makes two tests inside the loop, when one
// would suffice (at the price of more tests outside.) Write a version with only
// one test inside the loop and measure the difference in run-time.
#include <stdio.h>

// binsearch: find `x` in `v[0] <= v[1] <= ... <= v[n-1]`
int binsearch(int x, int v[], int n);
// binsearch: version two
int binsearch_v2(int x, int v[], int n);

int main() {
  int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int x = 9;
  printf("binary search result: %d\n", binsearch(x, sorted_array, 10));
  printf("binary search result: %d\n", binsearch_v2(x, sorted_array, 10));
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if (x == v[mid])
      return mid;
    else if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int binsearch_v2(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }
  if (low == high && x == v[low])
    return low;
  else
    return -1;
}
