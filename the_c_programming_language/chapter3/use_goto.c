#include <stdio.h>

int main() {
  int a[] = {1, 2, 3, 4};
  int b[] = {8, 27, 6, 7, 5};

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 5; ++j)
      if (a[i] == b[j])
        goto found;
      else
        goto notfound;

found:
  printf("find common value in array a and b\n");
notfound:
  printf("not found\n");

  // code involving a goto can always be written without one
  int found = 0;
  for (int i = 0; i < 4 && !found; ++i)
    for (int j = 0; j < 5 && !found; ++j)
      if (a[i] == b[j])
        found = 1;
  if (found)
    // got one: a[i-1] == b[j-1]
    printf("find common value in array a and b\n");
  else
    // didn't find any common element
    printf("not found\n");

  return 0;
}
