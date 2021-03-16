#include <stdio.h>
#include <ctype.h>

#include "calc.h"


// getop: get next character or numeric operand
int getop(char s[]) {
  int i, c;
  // skip whitespaces and tabs
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';  // why?
  // not a positive or negative number, not a string,
  // may be operators or newline char
  if (!isalpha(c) && !isdigit(c) && c != '.' && c != '-')
    return c;
  if (c == '-' && !isdigit(s[1] = getch())) {
    // minus operator `-`
    ungetch(s[1]); // otherwise the `\n` right after `-` will be discarded
    return c;
  } else if (c == '-')
    // push back on input
    ungetch(s[1]);

  i = 0;

  if (isalpha(c)) {
    while(isalpha(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    if (i > 1)
      return FUNCTION;
    else
      return s[0];
  }

  if (isdigit(c) || c == '-')  // collect integer part
    // prefix ++, due to s[0] already hold one digit
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')  // collect fraction part
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';  // replace the character which is not a part of number

  if (c != EOF) ungetch(c);
  if (s[0] == '-' || isdigit(s[0]))
    return NUMBER;
  return -1;  // unexcept situation
}
