// Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of
// type t . (Block structure will help.)
#include <stdio.h>

#define MAXCHAR 100

#define swap(t, x, y) \
  char tmp = t[x]; \
  t[x] = t[y]; \
  t[y] = tmp;

// reverse the string `s` in place, recursive version
void reverse_string(char s[], int low, int high);

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
