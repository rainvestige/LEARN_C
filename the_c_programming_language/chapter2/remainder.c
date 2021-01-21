#include <stdio.h>

int is_leap_year(int year);

int main() {
  int year;

  year = 2001;
  if (is_leap_year(year))
    printf("%d is a leap year\n", year);
  else
    printf("%d is not a leap year\n", year);
  return 0;
}

int is_leap_year(int year) {
  int ret;

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    ret = 1;
  else
    ret = 0;

  return ret;
}
