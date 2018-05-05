#include <stdio.h>

int factorial(int input)
{
  if (input==0)
  {
     return 1;
  }
else
  {
    return input * factorial(input-1);
  }
}

int fibnacci(int input)
{
    if(input == 0 || input == 1)
    {
        return 1;
    }
    else
    {
     return(fibnacci(input-1)+fibnacci(input-2));
    }
}

int main()
{
  int fact,fibnaci,i;
  fact=factorial(5);
  printf("The Factorial is %d \n" , fact);

  for(i=0;i<45;i++)
  {
     printf("Value of i = %d Series %d \n ",i,fibnacci(i));
  }
  return 0;
}
