// Exercise 2-6. Write a function `setbits(x,p,n,y)` that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.
//
// Exercise 2-7. Write a function `invert(x,p,n)` that returns `x` with the `n`
// bits that begin at position `p` inverted (i.e., 1 changed into 0 and vice
// versa), leaving the others unchanged.
//
// Exercise 2-8. Write a function `rightrot(x, n)` that returns the value of the
// integer `x` rotated to the right by `n` positions.
#include <stdio.h>

// getbits: get n bits from position p
unsigned getbits(unsigned x, int p, int n);
// setbits: set n bits from position p in x
unsigned setbits(unsigned x, int p, int n, unsigned y);
// invert: invert n bits from position p in x
unsigned invert(unsigned x, int p, int n);
// rightrot: rotate `x` to the right by n positions
unsigned rightrot(unsigned x, int n);
// compute the word length of specific type (unsigned)
int word_length(void);

int main() {
  unsigned int x = 0x8f4;
  unsigned int y = 0x8f;
  int p, n;
  p = 4;
  n = 3;
  printf("x = %x, y = %x, p = %d, n = %d\n", x, y, p, n);
  printf("get %d bits from position %d of %x\n", n, p, x);
  printf("-> %x\n", getbits(x, p, n));
  printf("set %d bits from position %d of %x to the rightmost %d bits of %x\n",
         n, p, x, n, y);
  printf("-> %x\n", setbits(x, p, n, y));
  printf("invert %d bits from position %d of %x\n", n, p, x);
  printf("-> %x\n", invert(x, p, n));
  printf("right rotate %x by %d positions\n", x, n);
  printf("-> %x\n", rightrot(x, n));

  return 0;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p , int n, unsigned y) {
  unsigned y_bit, trail_bit;
  unsigned trail_mask;

  // getbits from `y`
  y_bit = getbits(y, n - 1, n);
  // retain the right most `p + 1 - n` bits
  trail_mask = ~(~0 << (p + 1 - n));
  trail_bit = trail_mask & x;
  // set bits from y
  x = ((x >> (p + 1 - n)) & (~0 << n)) | y_bit;
  x = (x << (p + 1 - n)) | trail_bit;
  return x;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned int trail_bit, trail_mask;

  trail_mask = ~(~0 << (p + 1 - n));
  trail_bit = x & trail_mask;
  x = (x >> (p + 1 - n)) ^ ~(~0 << n);
  x = (x << (p + 1 - n)) | trail_bit;
  return x;
}

unsigned rightrot(unsigned x, int n) {
  unsigned mask, trail_bit;

  mask = ~(~0 << n);
  trail_bit = x & mask;
  x = x >> n;
  // how to determine the length of unsigned word
  x = x | trail_bit << (word_length() - n);

  return x;
}

int word_length(void) {
  int i;
  // the mandatory type cast limit the length
  unsigned x = (unsigned)~0;
  for (i = 0; x > 0; ++i)
    x = x >> 1;

  return i;
}
