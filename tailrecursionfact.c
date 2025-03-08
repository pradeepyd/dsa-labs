#include <stdio.h>
long int fact(int n, long int acc)
{
    if (n == 1)
        return acc;
    else 
        return fact(n-1, acc*n);
}
int main()
{
    int n;
    printf("Enter the value:");
    scanf("%d",&n);
    printf("The answer is %ld\n",fact(n,1));
    return 0;
}
