// Exercise 2-4. Write an alternative version of `squeeze(s1, s2)` that deletes
// each character in `s1` that matches any character in the string `s2`.
#include <stdio.h>

#define MAXLINE 1000

// squeeze: delete all `c` from `s`
void squeeze(char s[], char c);
// squeeze_: delete each character in `s1` that matches any character in `s2`
void squeeze_(char s1[], char s2[]);
// strcat: concatenate `t` to end of `s`; `s` must be big enough
void my_strcat(char s[], char t[]);
// whether `c` matches any character in the string `s`
int char_in_str(char c, char s[]);

int main() {
  char s[MAXLINE] = "Hello, world!";
  char t[MAXLINE] = "Xiao xin yu";
  //char c = 'o';
  char squeeze_chars[] = "Hol";
  printf("%s\n", s);
  squeeze_(s, squeeze_chars);
  printf("%s\n", s);

  my_strcat(s, t);
  printf("%s\n", s);

  return 0;
}

void squeeze(char s[], char c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; ++i) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

void squeeze_(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; ++i) {
    if (!char_in_str(s1[i], s2))
      s1[j++] =  s1[i];
  }
  s1[j] = '\0';
}

void my_strcat(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (s[i] != '\0') {
    i++;
  }

  while (t[j] != '\0')
    s[i++] = t[j++];

  s[i] = '\0';
}

int char_in_str(char c, char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    if (s[i] == c)
      return 1;
  return 0;
}
