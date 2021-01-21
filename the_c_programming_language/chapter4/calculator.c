#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <ctype.h>

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define MAXVAL 100  // maximum depth of val stack
#define BUFSIZE 100

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

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
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
        printf("\t%.8g\n", pop());
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
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// getop: get next character or numeric operand
int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t' || c == '\n')
    ;
  s[1] = '\0';  // why?
  if (!isdigit(c) && c != '.' && c != '-')
    return c;  // not a number, may be operators
  if (c == '-' && !isdigit(s[1] = getch()))
    // binary operator `-`
    return c;
  else
    // push back on input
    ungetch(s[1]);

  i = 0;
  if (isdigit(c) || c == '-')  // collect integer part
    // prefix ++, due to s[0] already hold one digit
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')  // collect fraction part
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';  // replace the character which is not a part of number
  if (c != EOF)
    ungetch(c);
  return NUMBER;
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

// print the top elements of the stack
void print_stack_top() {
  printf("%f\n", val[sp - 1]);
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
