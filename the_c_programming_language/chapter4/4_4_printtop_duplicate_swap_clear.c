// Exercise 4-4. Add the commands to print the top elements of the stack without
// popping, to duplicate it, and to swap the top two elements. Add a command to
// clear the stack.
//
// By Shawshary

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define MAXVAL 100  // maximum depth of val stack
#define BUFSIZE 100

// globals
int sp = 0;  // next free stack position
double val[MAXVAL];  // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;  // next free position in buf

// functions
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print_stack_top(void);
void duplicate_top(void);
void swap_top_two(void);
void clear_stack(void);

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
      case 'd':
        duplicate_top();
        break;
      case '?':
        print_stack_top();
        break;
      case 's':
        swap_top_two();
        break;
      case 'c':
        clear_stack();
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

// getop: get next character or numeric operand
int getop(char s[]) {
  int i, c;
  // skip whitespaces and tabs
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';  // why?
  // not a positive or negative number, may be operators or newline char
  if (!isdigit(c) && c != '.' && c != '-')
    return c;
  if (c == '-' && !isdigit(s[1] = getch())) {
    // minus operator `-`
    ungetch(s[1]); // otherwise the `\n` right after `-` will be discarded
    return c;
  } else if (c == '-')
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
  if (s[0] == '-' || isdigit(s[0]))
    return NUMBER;
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
