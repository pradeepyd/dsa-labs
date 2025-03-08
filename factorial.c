
#include<stdio.h>
int fact(int n)
{
    if(n==0||n==1)
    return 1;
    else
    return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter the value: ");
    scanf("%d" , &n);
    fact(n);
    printf("the factorial is %d" , fact(n));
    return 0;
}
