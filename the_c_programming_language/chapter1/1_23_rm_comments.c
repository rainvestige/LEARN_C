// 1-23. Write a program to remove all comments from a C program. Don't forget
// to handle quoted strings and character constants properly. C comments don't
// nest.
//
// _Date: 2021.01.01 Friday_ Use `getchar()` to get the program.
#include <stdio.h>

#define MAXLINE 10000
#define NOT_IN_QUOTE 1
#define IN_QUOTE 0

int get_text_stream(char s[], int maxline);
void rm_comment(char from[], char to[]);
void print_text_stream(char s[]);

int main() {
  char text_str[MAXLINE];
  char rm_comment_str[MAXLINE];

  while (get_text_stream(text_str, MAXLINE) > 0) {
    rm_comment(text_str, rm_comment_str);
    printf("-----------------//--------split line-------/*------*/------------\n");
    print_text_stream(rm_comment_str);
  }

  return 0;
}

int get_text_stream(char s[], int maxline) {
  int c, nline, i;

  nline = 0;
  for (i = 0; (c = getchar()) != EOF && i < maxline -1;/* i am comment */ ++i) {
    s[i] = c;
    if (c == '\n')
      nline++;
  }
  if (c == EOF)
    s[i] = EOF;
  if (i == maxline -1)
    s[i] = EOF;
  ++nline;  // view the EOF as special newline character
  return nline;
}

void rm_comment(char from[], char to[]) {
  int i, j, k_left, k_right, right_quote, left_quote;

  j = 0;
  for (i = 0; from[i] != EOF; ++i) {
    if (from[i] == '/' && from[i+1] == '/') {
      // meet comment string start with `//`
      // verify whether the `//` in a quoted string (default not)
      /* comment for test
       * i am comment
       * i am also comment
       * i am the last line comment
       */
      k_left = 1;
      k_right = 2;
      right_quote = left_quote = 0;
      while (from[i+k_right] != '\n') {
        if (from[i+k_right] == '"')
          right_quote = 1;
        ++k_right;
      }
      while (from[i-k_left] != '\n') {
        if (from[i-k_left] == '"')
          left_quote = 1;
        ++k_left;
      }
      if (right_quote == 0 || left_quote == 0){
        // skip the comment to the nearest newline character
        to[j] = '\n';
        i += k_right;  // remove the comment
        ++j;
      } else {
        // `//` in double quotes
        to[j] = from[i];
        ++j;
      }
    } else if (from[i] == '/' && from[i+1] == '*') {
      // meet comment string start with `/*`
      // verify whether the `//` in a quoted string (default not)
      k_left = 1;
      k_right = 2;
      right_quote = left_quote = 0;
      while (from[i+k_right] != '\n') {
        if (from[i+k_right] == '"')
          right_quote = 1;
        ++k_right;
      }
      while (from[i-k_left] != '\n' && i - k_left >= 0) {
        if (from[i-k_left] == '"')
          left_quote = 1;
        ++k_left;
      }
      if (left_quote == 0 || right_quote == 0) {
        // not in double quotes, find the paired `*/`
        k_right = 2;
        while (from[i+k_right] != '*' || from[i+k_right+1] != '/') {
          ++k_right;
        }
        // since we do not know what character exists after `*/`, we do not
        // perform the assignment.
        i += k_right + 1; // remove the comment
      } else {
        to[j] = from[i];
        ++j;
      }
    } else {
      // not comment leading character
      to[j] =  from[i];
      ++j;
    }
  }
  to[j] = EOF;
}

void print_text_stream(char s[]) {
  int i;

  for (i = 0; s[i] != EOF; ++i) {
    putchar(s[i]);
  }
  putchar('\n');
}
