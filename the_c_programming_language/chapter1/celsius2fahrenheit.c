#include <stdio.h>

int main() {
  /* print Celsius-Fahrenheit table
   * for Celsius = -10, -9, ..., 20;
   */
  float lower, upper, step;
  float celsius, fahr;

  lower = -10.0;
  upper = 20.0;
  step = 1.0;
  celsius = lower;

  printf("Celsius\tFahrenheit\n");
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%6.1f\t%3.0f\n", celsius, fahr);
    celsius += step;
  }

}
