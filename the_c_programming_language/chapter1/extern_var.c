#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline_(void);
void copy(void);

// print longest input line; specialized version
int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline_()) > 0)
    if (len > max) {
      max = len;
      copy();
    }

  if (max > 0)
    printf("%s", longest);

  return 0;
}


int getline_(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';  // use '\0' to mark the string end

  return i;
}

void copy(void) {
  int i;
  extern char line[], longest[];

  for (i = 0; line[i] != '\0'; ++i) {
    longest[i] = line[i];
  }
}
