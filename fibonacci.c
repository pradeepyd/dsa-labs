#include<stdio.h>
int fibo(int n )
{
    if(n==1||n==2)
    return 1;
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
    
}
int main()
{
    int a;
    printf("Enter the element: ");
    scanf("%d" , &a);
    printf("The %dth term fibonacci  is %d" , a, fibo(a));
}