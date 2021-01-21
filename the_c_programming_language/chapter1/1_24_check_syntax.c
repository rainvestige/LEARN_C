// Exercise 1-24. Write a program to check a C program of rudimentary syntax
// errors like unmatched parentheses, brackets and braces. Don't forget about
// quotes, both single and double, escape sequences, and comments.
//
// parentheses, brackets and braces can cover multilines, however the quotes
// must be in the same line.
#include <stdio.h>

#define MAXLINE 10000
#define NUM_SYNTAX_CHAR 100

typedef struct Syntax {
  int row;
  int col;
  int flag;
} Syntax;

int get_text_stream(char s[], int maxline);
void check_syntax(char s[]);
void print_error_msg(Syntax error[], int idx, char s[]);



int main() {
  char text_stream[MAXLINE];

  while (get_text_stream(text_stream, MAXLINE) > 0) {
    check_syntax(text_stream);
  }

  return 0;
}

int get_text_stream(char s[], int maxline) {
  int c, nline, nchar;

  nline = 1;
  nchar = 0;
  while ((c = getchar()) != EOF && nchar < maxline - 1) {
    s[nchar] = c;
    if (c == '\n')
      ++nline;
    ++nchar;
  }
  s[nchar] = EOF;

  return nchar;
}

void check_syntax(char s[]) {
  int i, row, col;
  int num_char = NUM_SYNTAX_CHAR;
  int idx_par, idx_bracket, idx_brace, idx_sq, idx_dq, idx_es, idx_com;
  int k_right, k_left;
  int left_squote_exist, left_dquote_exist;
  int right_squote_exist, right_dquote_exist;
  int left_comment_exist, right_comment_exist;
  int not_in_quotes, not_in_comment1, not_in_comment2, not_in_comment;
  Syntax par[num_char], bracket[num_char], brace[num_char];
  Syntax squote[num_char], dquote[num_char];
  Syntax escapes[num_char], comment[num_char];

  idx_par = idx_bracket = idx_brace = idx_sq = idx_dq = idx_es = idx_com = 0;
  row = col = 1; // position used to  locate the syntax errors

  for (i = 0; s[i] != EOF; ++i) {
    // whether in single or double quotes, don't consider whether in comment
    k_right = k_left =  1;
    left_squote_exist = left_dquote_exist = 0;
    right_squote_exist = right_dquote_exist = 0;
    while (s[i + k_right] != '\n' && s[i + k_right] != EOF) {
      if (s[i + k_right] == '"' && s[i + k_right - 1] != '\\')
        ++right_dquote_exist;
      else if (s[i + k_right] == '\'' && s[i + k_right - 1] != '\\')
        ++right_squote_exist;
      ++k_right;
    }
    while (i - k_left >= 0 && s[i - k_left] != '\n') {
      if (s[i - k_left] == '"' &&
          (i - k_left == 0 || s[i - k_left - 1] != '\\' ))
        ++left_dquote_exist;
      else if (s[i - k_left] == '\'' &&
               (i - k_left == 0 || s[i - k_left - 1] != '\\'))
        ++left_squote_exist;
      ++k_left;
    }
    if ((left_squote_exist && right_squote_exist) ||
        (left_dquote_exist && right_dquote_exist))
      not_in_quotes = 0;
    else
      not_in_quotes = 1;

    // whether in comments, don't consider whether in quotes
    k_right = k_left = 1;
    left_comment_exist = right_comment_exist = 0;
    // special case, at the first two characters.
    if (i < 2)
      not_in_comment1 = 1;
    // whether in `//`
    while (i - k_left - 1 >= 0 && s[i-k_left] != '\n') {
      // three slashes ?
      if (s[i-k_left-1] == '/' && s[i-k_left] == '/') {
        not_in_comment1 = 0;
        break;
      } else {
        not_in_comment1 = 1;
      }
      ++k_left;
    }
    // whether in `/**/`
    k_left = 1;
    if (i < 2)
      not_in_comment2 = 1;
    while (i - k_left - 1 >= 0) {
      if (s[i-k_left-1] == '/' && s[i-k_left] == '*') {
        left_comment_exist = 1;
        break;
      } else if (s[i-k_left-1] == '*' && s[i-k_left] == '/') {
        left_comment_exist = 0;
        break;
      }
      ++k_left;
    }
    while (s[i+k_right] != EOF) {
      if (s[i+k_right] == '*' && s[i+k_right+1] == '/') {
        right_comment_exist = 1;
        break;
      } else if (s[i+k_right] == '/' && s[i+k_right+1] == '*') {
        right_comment_exist = 0;
        break;
      }
      ++k_right;
    }

    if(left_comment_exist && right_comment_exist)
      not_in_comment2 = 0;
    else
      not_in_comment2 = 1;

    // combine `//` and `/**/`
    if (not_in_comment1 && not_in_comment2)
      not_in_comment = 1;
    else
      not_in_comment = 0;


    if (s[i] == '(' && not_in_quotes && not_in_comment) {
      // record the parentheses (push)
      par[idx_par].row = row;
      par[idx_par].col = col;
      par[idx_par].flag = 1;
      ++idx_par;
    } else if (s[i] == ')' && not_in_quotes && not_in_comment) {
      // neutralize the left parentheses (pop)
      if (idx_par >= 1) {
        par[idx_par-1].row = 0;
        par[idx_par-1].col = 0;
        par[idx_par-1].flag = 0;
        --idx_par;
      } else {
        printf("right parentheses syntax error occurs at row = %d, column = %d\n",
               row, col);
      }
    } else if (s[i] == '[' && not_in_quotes && not_in_comment) {
      // record the brackets (push)
      bracket[idx_bracket].row = row;
      bracket[idx_bracket].col = col;
      bracket[idx_bracket].flag = 1;
      ++idx_bracket;
    } else if (s[i] == ']' && not_in_quotes && not_in_comment) {
      // neutralize the left bracket (pop)
      if (idx_bracket >= 1) {
        bracket[idx_bracket-1].row = 0;
        bracket[idx_bracket-1].col = 0;
        bracket[idx_bracket-1].flag = 0;
        --idx_bracket;
      } else {
        printf("right bracket syntax error occurs at row = %d, column = %d\n",
               row, col);
      }
    } else if (s[i] == '{' && not_in_quotes && not_in_comment) {
      // record the curly braces (push)
      brace[idx_brace].row = row;
      brace[idx_brace].col = col;
      brace[idx_brace].flag = 1;
      ++idx_brace;
    } else if (s[i] == '}' && not_in_quotes && not_in_comment) {
      // neutralize the left braces (pop)
      if (idx_brace >= 1) {
        brace[idx_brace-1].row = 0;
        brace[idx_brace-1].col = 0;
        brace[idx_brace-1].flag = 0;
        --idx_brace;
      } else {
        printf("right brace syntax error occurs at row = %d, column = %d\n",
               row, col);
      }
    }

    // check quotes syntax, both single and double
    if (s[i] == '\'' && (i == 0 || s[i-1] != '\\') && not_in_comment &&
        not_in_quotes) {
      if ((left_squote_exist + right_squote_exist) % 2 == 0) {
        squote[idx_sq].row = row;
        squote[idx_sq].col = col;
        squote[idx_sq].flag = 1;
        ++idx_sq;
      } else {
        squote[idx_sq-1].row = 0;
        squote[idx_sq-1].col = 0;
        squote[idx_sq-1].flag = 0;
        --idx_sq;
      }
    } else if (s[i] == '"' && (i == 0 || s[i-1] != '\\') && not_in_comment &&
               not_in_quotes) {
      if ((left_dquote_exist + right_dquote_exist) % 2 == 0) {
        dquote[idx_dq].row = row;
        dquote[idx_dq].col = col;
        dquote[idx_dq].flag = 1;
        ++idx_dq;
      } else {
        dquote[idx_dq-1].row = 0;
        dquote[idx_dq-1].col = 0;
        dquote[idx_dq-1].flag = 0;
        --idx_dq;
      }
    }

    // check escape sequences
    if (s[i] == '\\' && (i == 0 || s[i-1] != '\\') &&
        !not_in_quotes && not_in_comment) {
      if (s[i+1] != 'a' && s[i+1] != 'b' && s[i+1] != 'e' && s[i+1] != 'f' &&
          s[i+1] != 'n' && s[i+1] != 'r' && s[i+1] != 't' && s[i+1] != 'v' &&
          s[i+1] != '\\' && s[i+1] != '\'' && s[i+1] != '\"' && s[i+1] != '?') {
        escapes[idx_es].row = row;
        escapes[idx_es].col = col;
        escapes[idx_es].flag = 1;
        ++idx_es;
      }
    }

    // check comments format
    if (s[i] == '/' && not_in_quotes && not_in_comment &&
        (i == 0 || (s[i-1] != '/' && s[i-1] != '*')) &&
        s[i+1] != '/' && s[i+1] != '*') {
      printf("Comment syntax error occurs at row = %d, column = %d\n",
             row, col);
    }
    // check comments pair /* */
    if (s[i] == '/' && s[i+1] == '*' && not_in_comment) {
      comment[idx_com].row = row;
      comment[idx_com].row = row;
      comment[idx_com].flag = 1;
      ++idx_com;
    } else if (s[i] == '*' && s[i+1] == '/' && not_in_comment) {
      if (idx_com >= 1) {
        comment[idx_com-1].row = 0;
        comment[idx_com-1].col = 0;
        comment[idx_com-1].flag = 0;
        --idx_com;
      } else {
        printf("right comment syntax error occurs at row = %d, column = %d\n",
               row, col);
      }
    }


    // update the position (row, col) at the end part of for loop
    if (s[i] == '\n') {
      ++row;
      col = 1;
    } else {
      ++col;
    }
  }


  // print the syntax error message
  print_error_msg(par, idx_par, "left parentheses");
  print_error_msg(bracket, idx_bracket, "left bracket");
  print_error_msg(brace, idx_brace, "left brace");
  print_error_msg(squote, idx_sq, "single quote");
  print_error_msg(dquote, idx_dq, "double quote");
  print_error_msg(escapes, idx_es, "escape sequences");
  print_error_msg(comment, idx_com, "left comment");
}

void print_error_msg(Syntax error[], int idx, char s[]) {
  if (idx == 0)
    printf("no %s syntax error\n", s);// no error message
  else {
    for (int i = 0; i < idx && error[i].flag == 1; ++i) {
      printf("%s syntax error occurs at row = %d, column = %d\n",
             s, error[i].row, error[i].col);
    }
    if (idx < 0) {

    }
  }
}
