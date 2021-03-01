#include <stdio.h>
#include <ctype.h>

int main()
{
  int spaces = 0;
  char c;
  while ((c = getchar()) != EOF)
  {
    if (c==' ')
    {
      spaces++;
    }else if (spaces!=0 )
    {
      printf(" ");
      putchar(c);
      spaces=0;
    }else {
      putchar(c);
    }
  }
  getchar();
}
