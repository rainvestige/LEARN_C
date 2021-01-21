#include <stdio.h>

#define IN 1
#define OUT 0

// Exercise 1-11. How would you test the word count program? What kinds of input
// are most likely to uncover bugs if there are any?
// The word at the end of the line with a dash connector, e.g. "sequen-\nce"

// Exercise 1-12. prints its input one word per line.
void print_one_word_per_line() {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n')) {
      if (state == IN)
        putchar('\n');
      state = OUT;
    }
    else {
      putchar(c);
      state =IN;
    }
  }
}

// Every time the program encounter the first character of a word, it counts one
// more word. The variable `state` records whether the program is currently in a
// word or not.
int main() {
  print_one_word_per_line();
  // count lines, words, and characters in input
  //int c, nl, nw, nc, state;
  //state = OUT;

  //nl = nw = nc = 0;
  //while ((c = getchar()) != EOF) {
  //  ++nc;
  //  if (c == '\n') {
  //    ++nl;
  //  }
  //  if (c == ' ' || c == '\t' || c == '\n')
  //    state = OUT;
  //  else if (state == OUT) {
  //    state = IN;
  //    ++nw;
  //  }
  //}
  //printf("%d %d %d\n", nl, nw, nc);
  return 0;
}
