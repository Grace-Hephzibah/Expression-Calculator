#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct stack
{
  char exp;
  struct stack *next;
}

int main()
{
  struct stack *operator= NULL;
  struct stack *operand= NULL;

  char expression[100];
  scanf("%s", expression);

  int l;
  l=strlen(expression);

  for(int i=0; i<=l; i++)
  {

  }

  return 0;
}
