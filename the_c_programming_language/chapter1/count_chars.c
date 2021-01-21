#include <stdio.h>

int main() {
  // count characters in input; 1st version
  //long nc;
  //nc = 0;

  //while (getchar() != EOF) {
  //  nc++;
  //  printf("The number of characters in input: %ld\n", nc);
  //}

  // count characters in input; 2nd version
  double nc_d;

  for (nc_d = 0; getchar() != EOF; ++nc_d)
    ;
  printf("The number of characters in input: %.0f\n", nc_d);

  return 0;
}
