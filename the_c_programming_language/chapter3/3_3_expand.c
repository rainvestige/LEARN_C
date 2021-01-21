// Exercise 3-3. Write a function `expand(s1, s2)` that expands shorthand
// notations like `a-z` in the string s1 into the equivalent complete list
// `abc...xyz` in s2. Allow for letters of either case and digits, and be
// prepared to handle cases like `a-b-c` and `a-z0-9` and `-a-z`. Arrange that a
// leading or trailing `-` is taken literally.
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

// expand: expand shorthand notations into the equivalent complete list
void expand(char from[], char to[]);
int get_text_stream(char s[], int maxline);

int main() {
  char s[MAXLINE];
  char t[MAXLINE];

  while (get_text_stream(s, MAXLINE) > 0) {
    expand(s, t);
    printf("%s\n", t);
  }

  return 0;
}

void expand(char from[], char to[]) {
  int i, j, k; // index for the two string

  for (i = 0, j = 0; from[i] != '\0'; ++i) {
    if (from[i] == '-' && (
       (islower(from[i-1]) && islower(from[i+1]) && from[i-1] < from[i+1]) ||
       (isupper(from[i-1]) && isupper(from[i+1]) && from[i-1] < from[i+1]) ||
       (isdigit(from[i-1]) && isdigit(from[i+1]) && from[i-1] < from[i+1]))) {
      for (k = 1; from[i-1] + k < from[i+1]; ++k)
        to[j++] = from[i-1] + k;
    } else
      to[j++] = from[i];
  }
  to[j] = '\0';
}

int get_text_stream(char s[], int maxline) {
  int c, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}
