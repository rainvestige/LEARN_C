#include <stdio.h>

// atoi: convert s to integer
int atoi(char s[]);
int lower(int c);

int main() {
  char s[] = "12345";
  printf("%d\n", atoi(s));

  char c = 'Z';
  printf("lower case for '%c': %c\n", c, lower(c));
  return 0;
}


int atoi(char s[]) {
  int ret;

  ret = 0;
  for (int i = 0; s[i] <= '9' && s[i] >= '0'; ++i) {
    ret = ret * 10 + (s[i] - '0');
  }
  return ret;
}

int lower(int c) {
  if (c >= 'A' && c <= 'Z')
    return c + ('a' - 'A');
  else if (c >= 'a' && c <= 'z')
    return c;
  else
    printf("not a letter\n");
}
