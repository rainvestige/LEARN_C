// Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa
// ; that is, convert an integer into a string by calling a recursive routine.
//
// By Shawshary
#include <stdio.h>

#define MAXCHAR 100

int ret_idx = 0;

// convert an integer to a string using recursive routine
void itoa_(int integer, char ret_str[]);

int main() {
  int number = 1243;
  char s[MAXCHAR];
  //ret_idx = 0;
  itoa_(number, s);
  printf("the integer number is: %d\n", number);
  printf("the corresponding string is: %s\n", s);
  //ret_idx = 0;
  number = 98264;
  itoa_(number, s);
  printf("the integer number is: %d\n", number);
  printf("the corresponding string is: %s\n", s);
  return 0;
}

void itoa_(int integer, char ret_str[]) {
  ret_idx = 0;
  if (integer / 10) {
    itoa_(integer/10, ret_str);
  }
  ret_str[ret_idx++] = integer % 10 + '0';
  ret_str[ret_idx] = '\0';
}
