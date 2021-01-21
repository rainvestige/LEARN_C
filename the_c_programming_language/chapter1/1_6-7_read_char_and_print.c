#include <stdio.h>

int main() {
  // copy input to output; 1st version
  int c;

  //c = getchar();

  //while(c != EOF) {
  //  putchar(c);
  //  c = getchar();
  //}

  // copy input to output; 2st version
  //while ((c = getchar()) != EOF) {
  //  putchar(c);
  //}

  // Exercise 1-6: Verify whether the expression `getchar() != EOF` is 0 or 1
  if ((c = getchar()) != EOF)
    printf("getchar() != EOF expression is 1\n");
  else
    printf("getchar() != EOF expression is 0\n");

  // Exercise 1-7: Print the value of symbolic constant EOF
  int c_eof = EOF;
  printf("The value of EOF is %d.\n", c_eof);
  return 0;
}
