#include <stdio.h>

// Exercise 1-8
// count lines in input
void newline_count() {
  int c, num_newlines;
  num_newlines = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ')
      num_newlines++;
  }
  printf("\nThe number of newlines in input: %d\n", num_newlines);
}

// count blanks in input
void blank_count() {
  int c, num_blanks;
  num_blanks = 0;

  while((c = getchar()) != EOF) {
    if (c == ' ')
      num_blanks++;
  }
  printf("\nThe number of blanks in input: %d\n", num_blanks);
}

// count tabs in input
void tab_count() {
  int c, num_tabs;
  num_tabs = 0;

  while((c = getchar()) != EOF) {
    if (c == '\t')
      num_tabs++;
  }
  printf("\nThe number of tabs in input: %d\n", num_tabs);
}

// Exercise 1-9
// copy the input to output, replacing each string of one or more blanks by a
// single blank
void to_single_blank() {
  int c;
  int previous_char = -1;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
    } else if (c == ' ' && previous_char != ' ') {
      putchar(c);
    } else {
      ; //done nothing
    }
    previous_char = c;
  }
}

// Exercise 1-10
// copy the input to output, replacing each tab by `\t`, each backspace by `\b`,
// and each backslash by `\\`
void escape_char_visible() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else
      putchar(c);
  }
}

int main() {
  //blank_count();
  //tab_count();
  //to_single_blank();
  escape_char_visible();
  return 0;
}
