// Exersice 2-5. Write the function `any(s1, s2)`, which returns the first
// location in a string `s1` where any character from the string `s2` occurs, or
// `-1` if `s1` contains no characters from `s2`. (The standard library function
// `strpbrk` does the same job but returns a pointer to the location.)
#include <stdio.h>

int any(char s1[], char s2[]);
int my_strlen(char s[]);

int main() {
  char foo[1000] = "Hello, world!";
  char bar[1000] = "d!";
  int loc;

  loc = any(foo, bar);
  printf("%s\n%*s\n", foo, loc + my_strlen(bar), bar);
  printf("`%s` occurs first at the %dth character of `%s`\n", bar, loc+1, foo);
  return 0;
}

int any(char s1[], char s2[]) {
  int i, j, loc;

  for (i = 0; s1[i] != '\0'; ++i) {
    // first character match
    if (s1[i] == s2[0]) {
      j = 1;
      while (s1[i+j] == s2[j] && s2[j] != '\0')
        ++j;
      if (s2[j] == '\0') {
        loc = i;
        break;
      }
      else
        loc = -1;
    } else
      loc = -1;
  }

  return loc;
}

int my_strlen(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  return i;
}
