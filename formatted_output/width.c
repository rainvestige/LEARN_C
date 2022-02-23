#include <stdio.h>

int main()
{
  char ch = 'a';
  int num = 0x11111110;
  printf("Character is %c\n", ch);
  printf("The integral number of character 'a' is %hhd\n", ch);
  printf("The integral number of character 'a' is %hd\n", ch);

  printf("Number is %d\n", num);
  printf("The corresponding character of number %d is %hhd\n", num, num);
  printf("The corresponding short of number %d is %hd\n", num, num);
  return 0;
}
