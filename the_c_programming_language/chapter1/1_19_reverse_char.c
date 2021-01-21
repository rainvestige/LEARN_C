// Exercise 1-19. Write a function reverse(s) that reverses the character
// string s. Use it to write a program that reverses its input a line at a time
#include <stdio.h>

#define MAXLINE 1000

void reverse_string(char s[], int len);
int getline_(char line[], int maxline);


int main() {
  int len;
  char line[MAXLINE];

  len = 0;
  while ((len = getline_(line, MAXLINE)) > 0) {
    printf("current line length: %d\n", len);
    if (line[len-1] == '\n')
      reverse_string(line, len-1);
    else
      reverse_string(line, len);
  }
  return 0;
}

int getline_(char line[], int maxline) {
  int c, i;

  i = 0;
  while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
      line[i] = c;
      ++i;
  }
  if (c == '\n') {
    line[i] = '\n';
    return i+1;
  }
  return i;
}

void reverse_string(char s[], int len) {
  int i;

  i = 0;
  while (len - 1 - i >= 0) {
    putchar(s[len-1-i]);
    ++i;
  }
  printf("\n");
}
