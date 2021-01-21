#include <stdio.h>

// bitcount: count 1 bits in x
int bitcount(unsigned x);

int main() {
  unsigned x = 0xfff;
  printf("%x have %d 1-bits\n", x, bitcount(x));
  return 0;
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x > 0; x >>= 1) {
    if (x & 01)
      ++b;
  }
  return b;
}
