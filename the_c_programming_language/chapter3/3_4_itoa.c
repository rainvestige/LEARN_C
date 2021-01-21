// Exercise 3-4. In a two's complement number representation, our version of
// `itoa` does not handle the largest negative number, that is, the value of n
// equal to `-(2^(wordsize-1)). Explain why not. Modify it to print that value
// correctly, regardless of the machine on which it runs.
//
// Because largest positive number is less than the largest negative number in
// absolute value. when we evaluate `n = -n`, it will cause overflow problem.
#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

// itoa: convert n to characters in s
void itoa(int n, char s[]);
// reverse: reverse string
void reverse(char s[]);

int main() {
  char s[MAXLINE];
  int n = INT_MIN;
  printf("integer: %d\n", n);
  itoa(n, s);
  printf("string: %s\n", s);
  return 0;
}

// the do-while is necessary, or at least convenient, since at least one
// character must be installed in the array `s`, even if `n` is zero.
void itoa(int n, char s[]) {
  int i, sign;
  long long n_;
  n_ = n;

  if ((sign = n_) < 0) // record sign
    n_ = -n_;  // make n positive !!may cause overflow!!
  i = 0;
  do {  // generate digits in reverse order
    s[i++] = n_ % 10 + '0';  // get next digit
  } while ((n_ /= 10) > 0);  // delete it
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
