#include<stdio.h>

int binaryconvert(int n)
{
    int div;
    //printf("\n Inside Bin Convert %d \n",n);
    if(n < 2)
    {
        printf("%d", n);
    }
    else
    {
        div = n/2;
        binaryconvert(div);
        printf("%d", (n%2));
    }
}
int main()
{
    int i=2,quot,remain;
    binaryconvert(i);
    return 0;
}
