#include <stdio.h>

// count lines in input
void newline_count() {
  int c, num_newlines;
  num_newlines = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ')
      num_newlines++;
  }
  printf("The number of newlines in input: %d\n", num_newlines);
}

// count blanks in input
void blank_count() {
  int c, num_blanks;
  num_blanks = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ')
      num_blanks++;
  }
  printf("The number of blanks in input: %d\n", num_blanks);
}

// count tabs in input
void tab_count() {
  int c, num_tabs;
  num_tabs = 0;

  while((c = getchar()) != EOF) {
    if (c == '\t')
      num_tabs++;
  }
  printf("The number of tabs in input: %d\n", num_tabs);
}

int main() {
  tab_count();
  return 0;
}
