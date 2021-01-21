// Exercise 4-2. Extend `atof` to handle scientific notation of the form
// `123.45e-6` where a floating-point number may be followed by e or E and an
// optionally signed exponent
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char s[]);
// power_exp: return base^exp
double power_exp(double base, int exp);
int getline_(char s[], int max);

int main() {
  char line[MAXLINE];

  while (getline_(line, MAXLINE) > 0) {
    printf("\t%f\n", atof(line));
  }
  return 0;
}

double atof(char s[]) {
  int i, sign, exp_sign;
  double val, power, exponent;

  for (i = 0; s[i] == ' '; ++i)  // skip white space
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')  // skip signed symbol
    i++;
  for (val = 0.0; isdigit(s[i]); ++i)
      val = val * 10.0 + (s[i] - '0');
  if (s[i] == '.')
    ++i;
  for (power = 1.0; isdigit(s[i]); ++i) {
    val = val * 10.0 + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E')
    ++i;
  exp_sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  for (exponent = 0.0; isdigit(s[i]); ++i)
    exponent = exponent * 10.0 + (s[i] - '0');
  if (exp_sign > 0)
    val = sign * val / power * power_exp(10, exponent);
  else if (exp_sign < 0)
    val = sign * val / power / power_exp(10, exponent);

  return val;
}

double power_exp(double base, int exp) {
  double ret = 1.0;
  for (int i = 0; i < exp; ++i) {
    ret = ret * base;
  }
  return ret;
}

int getline_(char s[], int max) {
  int i, c;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}
