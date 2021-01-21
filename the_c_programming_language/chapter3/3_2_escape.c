// Exercise 3-2. Write a function `escape(s, t)` that converts characters like
// newline and tab into visible escape sequences like `\n` and `\t` as it copies
// the string `t` to `s`. Use a switch. Write a function for the other direction
// as well, converting escape sequences into the real characters.
#include <stdio.h>

#define MAXLINE 1000

// escape: converts characters into visible escape sequences
void escape(char s[], char t[]);
// reverse_escape: converts escape sequences into the real characters
void reverse_escape(char s[], char t[]);

int main() {
  char text_stream[MAXLINE];
  char tmp[MAXLINE];
  char reverse_es[MAXLINE];
  int c, i;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; ++i)
    text_stream[i] = c;
  text_stream[i] = '\0';

  escape(text_stream, tmp);
  printf("\n%s\n", tmp);
  reverse_escape(tmp, reverse_es);
  printf("\n%s\n", reverse_es);
  return 0;
}

void escape(char s[], char t[]) {
  int i, j;

  j = 0;
  for (i = 0; s[i] != '\0'; ++i) {
    switch (s[i]) {
      case '\t':
        t[j++] = '\\';
        t[j++] = 't';
        break;
      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
        break;
      default:
        t[j++] = s[i];
    }
  }
  t[j] = '\0';
}

void reverse_escape(char s[], char t[]) {
  int i, j;

  j = 0;
  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] == '\\') {
      switch(s[i+1]) {
         case 't':
           t[j++] = '\t';
           ++i;
           break;
         case 'n':
           t[j++] = '\n';
           ++i;
           break;
         default:
           t[j++] = s[i];
           break;
      }
    } else
      t[j++] = s[i];

  }
  t[j] = '\0';
}
