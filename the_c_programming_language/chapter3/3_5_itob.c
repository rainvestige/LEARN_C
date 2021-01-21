// Exercise 3-5. Write the function `itob(n,s,b)` that converts the integer `n`
// into a base `b` character representation in the string `s`. In particular,
// itob(n,s,16) formats `s` as a hexadecimal integer in `s`
#include <stdio.h>

#define MAXCHAR 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  int n = 15;
  int b = 16;
  char s[MAXCHAR];
  itob(n, s, b);
  printf("integer: %d\tbase: %d\n", n, b);
  printf("string: %s\n", s);
  return 0;
}

void itob(int n, char s[], int b) {
  int sign, i;
  long long n_long;
  n_long = n;
  sign = n;
  if (n_long < 0)
    n_long = -n_long;
  i = 0;
  do {
    switch (n_long % b) {
      case 0: case 1: case 2: case 3: case 4:
      case 5: case 6: case 7: case 8: case 9:
        s[i++] = n_long % b + '0';
        break;
      default:
        s[i++] = n_long % b - 10 + 'a';
        break;
    }
  } while ((n_long /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int low, high, i;
  int tmp;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  high = i - 1;
  low = 0;
  while (low < high) {
    tmp = s[low];
    s[low] = s[high];
    s[high] = tmp;
    low++;
    high--;
  }
}
