#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp;
static double val[MAXVAL];

// push: push f onto value stack
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
    //printf("value %g pushed\n", f);
  } else
    printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void) {
  if (sp > 0) {
    //printf("value %g poped\n", val[--sp]);
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// print the top elements of the stack
void print_stack_top() {
  if (sp > 0)
    printf("stack top elements: %.8g\n", val[sp - 1]);  // do not change `sp`
  else
    printf("error: stack empty\n");
}

// duplicate the stack, return the next stack free position
void duplicate_top(void) {
  push(val[sp-1]);
}

// swap the top two elements
void swap_top_two() {
  int tmp1, tmp2;
  tmp1 = pop();
  tmp2 = pop();
  push(tmp1);
  push(tmp2);
}

// clear the stack
void clear_stack() {
  sp = 0;
}
