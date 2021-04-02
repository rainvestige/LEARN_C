#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <string.h>  // for strcmp()

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define FUNCTION 'f'  // signal that a function name was found
#define MAXVAL 100  // maximum depth of val stack
//#define BUFSIZE 100
// Exercise 4-8. suppose that there will never be more than one character of
// pushback. Modify `getch` and `ungetch` accordingly.
#define BUFSIZE 1

int sp = 0;  // next free stack position
double val[MAXVAL];  // value stack

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

int getop(char []);
void push(double);
double pop(void);
void print_stack_top(void);
int duplicate_stack(double []);
void swap_top_two(void);
void clear_stack(void);

int getch(void);
void ungetch(int);

// Reverse Polish Calculator
int main() {
  int type;
  double op2;
  char s[MAXOP];
  double recent_print_val;

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case FUNCTION:
        if (!strcmp(s, "sin"))
          push(sin(pop()));
        else if (!strcmp(s, "exp"))
          push(exp(pop()));
        else if (!strcmp(s, "pow")) {
          op2 = pop();
          push(pow(pop(), op2));
        } else
          printf("unknown function name: %s\n", s);
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
      case '\n':
        // Exercise 4-6. Add a variable for the most recently printed value
        recent_print_val = pop();
        printf("\t%.8g\n", recent_print_val);
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

// push: push f onto value stack
void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
    //printf("value %g pushed\n", f);
  }
  else
    printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void) {
  if (sp > 0) {
    //printf("value %g poped\n", val[--sp]);
    return val[--sp];
  }
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// getop: get next character or numeric operand
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  //s[1] = '\0';  // why?
  if (!isalpha(c) && !isdigit(c) && c != '.' && c != '-')
    return c;  // not a number, may be operators or newline char
  if (c == '-' && !isdigit(s[1] = getch()))
    // minus operator `-`
    return c;
  else if (c == '-')
    // push back on input
    ungetch(s[1]);

  i = 0;
  if (isdigit(c) || c == '-')  // collect integer part
    // prefix ++, due to s[0] already hold one digit
    while (isdigit(s[++i] = c = getch()))
      ;
  else if (isalpha(c))  // collect math function name
    while (isalpha(s[++i] = c = getch()))
      ;

  if (c == '.')  // collect fraction part
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';  // replace the character which is not a part of number
  if (c != EOF)
    ungetch(c);
  if (s[0] == '-' || isdigit(s[0]))
    return NUMBER;
  else if (isalpha(s[0]))
    return FUNCTION;  // character string
  return -1;  // unexcept situation
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

// Exercise 4-7. Write a routine `ungets(s)` that will push back an entire
// string onto the input. Should `ungets` know about `buf` and `bufp`, or should
// it just use `ungetch`?
//
// `ungets` doesn't need to know about `buf` and `bufp`, it just use `ungetch`
// to do the push back operation.
//
// push back an entire string onto the input
void ungets(char s[]) {
  for (int i = strlen(s) - 1; i >= 0; i--) {
    ungetch(s[i]);
  }
}

// print the top elements of the stack
void print_stack_top() {
  printf("%.8g\n", val[sp - 1]);
}

// duplicate the stack, return the next stack free position
int duplicate_stack(double dup_stack[]) {
  int i;
  for (i = 0; i < sp; ++i)
    dup_stack[i] = val[i];
  return i;  // i = sp
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
