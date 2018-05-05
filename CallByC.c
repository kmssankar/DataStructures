#include <stdio.h>

void add(int *x,int *y)
{
    *x+=*x;
    *y+=*y;
    printf("\nvalue of x and Y %d %d",*x,*y);
}
struct Mydd
{
    float k;
    union Myunion
    {
        float F1;
        int I1;
    } r1;
};

int main()
{
    int x=5.5;
    struct Mydd DD1;
    add(&x,&x);
    printf("\nValue of x %d",x);
    printf("\n Size of float and int %d %d",sizeof(DD1.k),sizeof(DD1.r1.I1));
    printf("\n Size of struct + union %u",sizeof(DD1));
    return 0;
}
