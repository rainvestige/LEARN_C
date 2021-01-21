// Exercise 2-1. Write a program to determine the ranges of `char, short, int`
// and `long` variables, both `signed` and `unsigned`, by printing appropriate
// values from standard headers and by direct computation. Harder if you compute
// them: determine the ranges of the various floating-opint types.
#include <stdio.h>
#include <limits.h>
#include <float.h>

int power(int base, int exp);

enum my_type {
  MY_CHAR = 1,
  MY_INT = 2,
  MY_FLOAT = 3,
  MY_DOUBLE = 4
};

int main() {
  printf("The header <limits.h> defines constants"
         "for the sizes of integral types\n");
  printf("char min: %d, char max: %d\n", CHAR_MIN, CHAR_MAX);
  printf("signed char min: %d, signed char max: %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("int min: %d, int max: %d\n", INT_MIN, INT_MAX);
  printf("short int min: %d, short int max: %d\n", SHRT_MIN, SHRT_MAX);
  printf("long int min: %ld, long int max: %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned char max: %u\n", UCHAR_MAX);
  printf("unsigned int max: %u\n", UINT_MAX);
  printf("unsigned short max: %u\n", USHRT_MAX);
  printf("unsigned long max: %lu\n", ULONG_MAX);
  printf("\v");

  printf("************************************************************\n");
  printf("The header <float.h> defines constants"
         "related to floating-point arithmetic\n");
  printf("radix of exponent representation: %d\n", FLT_RADIX);
  printf("floating-point rounding mode for addition: %d\n", FLT_ROUNDS);
  printf("decimal digits of float percision: %d\n", FLT_DIG);
  printf("floating-point smallest number: %E\n", FLT_EPSILON);
  printf("number of base `FLT_RADIX` in mantissa: %d\n", FLT_MANT_DIG);
  printf("max float: %f, min float %f\n", FLT_MAX, FLT_MIN);
  printf("max float exponent: %d, min float exponent: %d\n",
         FLT_MAX_EXP, FLT_MIN_EXP);

  printf("decimal digits of double percision: %d\n", DBL_DIG);
  printf("double floating-point smallest number: %E\n", DBL_EPSILON);
  printf("number of base `DBL_RADIX` in mantissa: %d\n", DBL_MANT_DIG);
  printf("max double: %f, min double %f\n", DBL_MAX, DBL_MIN);
  printf("max double exponent: %d, min double exponent: %d\n",
         DBL_MAX_EXP, DBL_MIN_EXP);

  return 0;
}

void compute_range(enum my_type type, int nbits) {
  int max, min;

  switch (type) {
    case MY_CHAR:
    case MY_INT:
      // default signed char
      max = power(2, nbits - 1) - 1;
      min = -power(2, nbits - 1);
      printf("char min: %d, char max: %d\n", min, max);
      break;
    case MY_FLOAT: break;
    case MY_DOUBLE: break;
  }
}

// base^exp
int power(int base, int exp) {
  int ret = 1;
  for (int i = 0; i < exp; ++i) {
    ret *= base;
  }
  return ret;
}
