#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "calc.h"

#define MAXOP 100

double last_printed;
extern int variable;
extern int sp;

// return true if `s` is a function name in `math.h`
int proc_math_func(char s[]) {
  double op2;

  if (!strcmp(s, "lp"))
    push(last_printed);
  else if (!strcmp(s, "cm"))
    clear_memory();
  else if (!strcmp(s, "sin"))
    push(sin(pop()));
  else if (!strcmp(s, "exp"))
    push(exp(pop()));
  else if (!strcmp(s, "pow")) {
    op2 = pop();
    push(pow(pop(), op2));
  } else {
    printf("unknown function name: %s\n", s);
    return 0;
  }
  return 1;
}

// Reverse Polish Calculator
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case FUNCTION:
        proc_math_func(s);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int)pop() % (int)op2);
        else
          printf("error: zero modular\n");
        break;
      case '#':
        duplicate_top();
        break;
      case '?':
        print_stack_top();
        break;
      case '!':
        swap_top_two();
        break;
      case '~':
        clear_stack();
        break;
      case '=':
        // 10 a = -> a = 10
        store_variables();
      case '\n':
        if (sp > 0)
          printf("\t%.8g\n", last_printed = pop());
        break;
      default:
        if (islower(type))
          fetch_variables(type);  // replace the var with its value
        else
          printf("error: unknown command %s\n", s);
        break;
    }
    variable = type;
  }
  return 0;
}
