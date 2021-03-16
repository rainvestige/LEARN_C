// Exercise 4-10. An alternate organization uses getline to read an entire input
// line; this makes getch and ungetch unnecessary. Revise the calculator to use
// this approach.
//
// By Shawshary

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <string.h>  // for strcmp()
#include <math.h>  // for math functions

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define FUNCTION 'f'  // signal that a function name was found
#define MAXVAL 100  // maximum depth of val stack
#define BUFSIZE 1
#define MAXVAR 26  // number of letter variables
#define MAXCHAR 100

// globals
int sp = 0;  // next free stack position
double val[MAXVAL];  // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

double mem[MAXVAR];
int variable;  // current input variable
double last_printed;

char line_str[MAXCHAR];  // storage for an entire line
int line_idx = 0;  // used to seperate operators and operands

// functions
int getop(char [], int line_len);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print_stack_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);
int proc_math_func(char []);

void store_variables(void);
void fetch_variables(int var);
void clear_memory(void);

void ungets(char s[]);

int getline_(void);

// Reverse Polish Calculator
int main() {
  int type;
  double op2;
  char s[MAXOP];
  int line_len;

  while ((line_len = getline_())) {
    line_idx = 0;  // everytime we get a newline, we set line idx to 0
    while ((type = getop(s, line_len)) != EOF/* && line_idx <= line_len*/) {
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
  }
  return 0;
}

// getop: get next character or numeric operand
int getop(char s[], int line_len) {
  int j, c;
  j = 0;
  while (line_idx < line_len) {
    s[0] = c = line_str[line_idx];
    if (c == ' ' || c == '\t') {
      ++line_idx;
      continue;
    }
    s[1] = '\0';
    // not a positive or negative number, not a string,
    // may be operators or newline char
    if (!isalpha(c) && !isdigit(c) && c != '.' && c != '-') {
      ++line_idx;
      return c;
    }
    if (c == '-' && !isdigit(s[1] = line_str[line_idx + 1])) {
      // minus operator `-`
      ++line_idx;
      return c;
    }

    j = 0;
    if (isalpha(c)) {
      while(isalpha(s[++j] = c = line_str[++line_idx]))
        ;
      s[j] = '\0';
      if (j > 1) {
        return FUNCTION;
      } else {
        return s[0];
      }
    }
    if (isdigit(c) || c == '-')  // collect integer part
      // prefix ++, due to s[0] already hold one digit
      while (isdigit(s[++j] = c = line_str[++line_idx]))
        ;
    if (c == '.')  // collect fraction part
      while (isdigit(s[++j] = c = line_str[++line_idx]))
        ;
    s[j] = '\0';  // replace the character which is not a part of number
    if (s[0] == '-' || isdigit(s[0])) {
      return NUMBER;
    }
  }

  return EOF;  // unexcept situation
}

// getch: get a (possibly pushed-back) character
int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

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

// push back an entire string onto the input
void ungets(char s[]) {
  for (int i = strlen(s) - 1; i >= 0; i--) {
    ungetch(s[i]);
  }
}

// read an entire input line, return the length of the input line
int getline_(void) {
  // `line_str[MAXCHAR]`
  int i, c;
  i = 0;
  while (i < MAXCHAR && (c = getchar()) != EOF && c != '\n') {
    line_str[i++] = c;
  }
  if (c == '\n')
    line_str[i++] = c;
  line_str[i] = '\0';
  return i;
}
