#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int main() {
  double sum, atof(char []);
  char line[MAXLINE];
  int getline_(char line[], int max);
  int atoi(char s[]);

  sum = 0;
  while (getline_(line, MAXLINE) > 0) {
    printf("\t%5.6f\n", sum += atof(line));
    printf("\t%d\n", atoi(line));
  }
  return 0;
}

// atof: convert string `s` to double
double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)  // skip white space
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); ++i)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); ++i) {
    //double frac = 0;
    //int k = 1;
    //frac += (s[i] - '0') / power(10, k++);
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  return sign * val / power;
}

int getline_(char line[], int max) {
  int i, c;

  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0';
  return i;
}

// atoi: convert string s to integer using atof
int atoi(char s[]) {
  //double atof(char s[]);
  return (int)atof(s);
}
