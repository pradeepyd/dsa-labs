#include<stdio.h>
long long int table[1001];
long int fibo(int n )
{
    if(n==1||n==2)
    return 1;
    else
    {
        if(table[n]==-1)
        table[n]=fibo(n-1)+fibo(n-2);
        return table[n];
    }
    
}
int main()
{
    int a ,i;
    printf("Enter the element: ");
    scanf("%d" , &a);
    for(i=0;i<1001;i++)
    table[i]=-1;
    printf("The %dth term fibonacci  is %ld\n" , a, fibo(a));
    return 0;
}