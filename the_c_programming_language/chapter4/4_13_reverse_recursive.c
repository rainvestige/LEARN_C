// Exercise 4-13. Write a recursive version of the function reverse(s) , which
// reverses the string s in place.
#include <stdio.h>

#define MAXCHAR 100

// reverse the string `s` in place, recursive version
void reverse_string(char s[], int low, int high);
// swap s[a] with s[b]
void swap(char s[], int a, int b);

int main() {
  char s[MAXCHAR] = "hello, world!";
  int str_len = 0;
  while (s[str_len++] != '\0')
    ;
  printf("the original string: %s\n", s);
  reverse_string(s, 0, str_len-2);  // exclude the '\0'
  printf("the reversed string: %s\n", s);
  return 0;
}

void reverse_string(char s[], int low, int high) {
  if (low < high) {
    reverse_string(s, low+1, high-1);
  }
  swap(s, low, high);
}

void swap(char s[], int a, int b) {
  char tmp;
  if (a == b)
    return;
  tmp = s[a];
  s[a] = s[b];
  s[b] = tmp;
}
