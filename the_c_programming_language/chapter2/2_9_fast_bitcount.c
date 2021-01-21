// Exercise 2-9. In a two's complement number system, `x &= (x - 1)` deletes the
// rightmost 1-bit in `x`. Explain why. Use this observation to write a faster
// version of `bitcount`
//
// the (x - 1) will invert the rightmost 1-bit and the remaining right bits,
// when applied & operation with x, the rightmost 1-bit and the remaining right
// bits will all be converted to 0.
#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned x = 0x4ff;
  printf("%#x have %d 1-bits\n", x, bitcount(x));
  return 0;
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; ++b)
    x &= x - 1;

  return b;
}
