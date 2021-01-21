// Exercise 2-3. Write a function `htoi(s)`, which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a throught f, and A
// through F.
#include <stdio.h>

int htoi(char s[]);
int my_strlen(char s[]);
int power(int base, int exp);

int main() {
  int c;
  char hex_digit[1000];
  int i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    hex_digit[i] = c;
    ++i;
  }
  hex_digit[i] = '\0';

  printf("\nhexadecimal: %s, equivalent integer value: %d\n",
         hex_digit, htoi(hex_digit));
  return 0;
}

// Convert a string of hexadecimal digits into its equivalent integer value
int htoi(char s[]) {
  int i, decimal;
  int len = my_strlen(s);
  int HEX_BASE = 16;
  int sum = 0;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    i = 2;
  else
    i = 0;


  while (s[i] != '\0') {
    // convert hexadecimal to decimal
    if (s[i] >= 'a' && s[i] <= 'f')
      decimal = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      decimal = s[i] - 'A' + 10;
    else if (s[i] >= '0' && s[i] <= '9')
      decimal = s[i] - '0';
    sum += decimal * power(HEX_BASE, len - (i + 1));
    ++i;
  }

  return sum;
}

int my_strlen(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  return i;
}

int power(int base, int exp) {
  int ret = 1;
  for (int i = 0; i < exp; ++i)
    ret *= base;
  return ret;
}
