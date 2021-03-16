#include <stdio.h>
#include "calc.h"

#define MAXVAR 26  // number of letter variables

static double mem[MAXVAR];
int variable;  // current input variable

// store variable value (a to z) to the corresponding location in `mem` and push
// back to top of stack
void store_variables(void) {
  if (variable >= 'a' && variable <= 'z') {
    pop();
    push(mem[variable-'a'] = pop());
  }
  else
    printf("unknown variable name\n");
}

// fetch var value from mem and push on to value stack
void fetch_variables(int var) {
  push(mem[var-'a']);
}

// set values of mem to 0
void clear_memory(void) {
  for (int i = 0; i < MAXVAR; i++)
    mem[i] = 0;
  printf("memory cleared\n");
}
