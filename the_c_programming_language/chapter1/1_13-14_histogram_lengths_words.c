#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define IN 1
#define OUT 0

// Exercise 1-14. Write a program to print a histogram of the frequencies of
// different characters in its input
void char_freq() {
  int NUM_CHAR = 26; // ignore the case sensitive
  int char_freq[NUM_CHAR];
  int c;

  for (int i = 0; i < NUM_CHAR; ++i)
    char_freq[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= 'A' && c <= 'Z')
      ++char_freq[c - 'A'];
    else if (c >= 'a' && c <='z')
      ++char_freq[c - 'a'];
  }

  // print the histogram with the bars horizontal.
  for (int i = 0; i < NUM_CHAR; ++i) {
    printf("\n%c: ", i + 'A');
    for (int j = 0; j < char_freq[i]; ++j)
      printf("|");
  }
}

// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.
int main() {
  // initialize the histogram

  int hist[MAX_WORD_LENGTH];
  int c, len_word, state;

  len_word = 0;
  state = OUT;
  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    hist[i] = 0;
  }

  // you should end the character strings by blanks, tabs or newlines.
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      state = IN;
      len_word++;
    } else if (state == IN) {
      ++hist[len_word];
      state = OUT;
      len_word = 0;
    }

  }

  // print the histogram with the bars horizontal.
  for (int i = 1; i < MAX_WORD_LENGTH; ++i) {
    printf("\nLength %2d: ", i);
    for (int j = 0; j < hist[i]; ++j)
      printf("|");
  }

  // print the histogram with the bars vertical.
  // hist[0] used to record the maximum length of words in input.
  for (int i = 1; i < MAX_WORD_LENGTH; ++i) {
    if (hist[i] >= hist[0])
      hist[0] = hist[i];
  }
  printf("\nThe maximum length of words in input: %d\n", hist[0]);
  for (int i = 1; i <= hist[0]; ++i) {
    for (int j = 1; j < MAX_WORD_LENGTH; ++j) {
      if (i <= hist[0] - hist[j])
        printf("   ");
      else
        printf(" _ ");
    }
    printf("\n");
  }
  for (int j = 1; j < MAX_WORD_LENGTH; ++j)
    printf("%2d ", j);
  printf("\n");

  char_freq();
  return 0;
}
