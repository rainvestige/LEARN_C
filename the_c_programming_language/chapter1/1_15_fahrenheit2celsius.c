#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300
 */

float fahr2celsius(float fahr);

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;  // lower limit of temperature scale
  upper = 300;  // upper limit
  step = 20;  // step size

  fahr = lower;
  printf("Fahr\tCelsius\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr - 32);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr += step;
  }

  for (fahr = 0; fahr <= 300; fahr += 20) {
    celsius = (5.0/9.0) * (fahr - 32);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
  }

  for (fahr = 300; fahr >= 0; fahr -= 20) {
    celsius = (5.0/9.0) * (fahr - 32);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
  }

  for (fahr = upper; fahr >= lower; fahr -= step) {
    celsius = fahr2celsius(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
  }
}

// Exercise 1.15. Rewrite the temperature conversion program of "Section 1.2" to
// use a function for conversion.
float fahr2celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32);
}
