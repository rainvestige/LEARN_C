#include <stdio.h>

#define MAXLINE 1000

// itoa: convert n to characters in s
void itoa(int n, char s[]);
// reverse: reverse string
void reverse(char s[]);

int main() {
  char s[MAXLINE];
  int n = -3124;
  printf("integer: %d\n", n);
  itoa(n, s);
  printf("string: %s\n", s);
  return 0;
}

// the do-while is necessary, or at least convenient, since at least one
// character must be installed in the array `s`, even if `n` is zero.
void itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0) // record sign
    n = -n;  // make n positive
  i = 0;
  do {  // generate digits in reverse order
    s[i++] = n % 10 + '0';  // get next digit
  } while ((n /= 10) > 0);  // delete it
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int i, len, low, high;
  int temp;
  for (i = 0; s[i] != '\0'; ++i)
    ;
  len = i;  // string length

  low = 0;
  high = len - 1;
  while (low < high) {
    temp = s[low];
    s[low] = s[high];
    s[high] = temp;
    low++;
    high--;
  }
}
