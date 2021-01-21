// Exercise 3-6. Write a version of `itoa` that accepts three arguments instead
// of two. The third argument is a minimum field width; the converted number
// must be padded with blanks on the left if necessary to make it wide enough.
#include <stdio.h>

#define MAXLINE 1000

// itoa: version with fixed width
void itoa(int n, char s[], int width);
void reverse(char s[]);

int main() {
  int n = -1500;
  int width = 10;
  char s[MAXLINE];
  itoa(n, s, width);
  printf("integer: %d\twidth: %d\n", n, width);
  printf("string: %s\n", s);
  return 0;
}

void itoa(int n, char s[], int width) {
  int sign, i;
  int b = 2;
  long long n_long;
  i = 0;
  sign = n;
  n_long = n;
  if (n_long < 0)
    n_long = -n_long;
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
  // fill blanks until fixed width if necessary
  while (i < width) {
    s[i++] = ' ';
  }
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
