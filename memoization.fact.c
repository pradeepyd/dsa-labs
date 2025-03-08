#include<stdio.h>
long long int table[500];
int fact(int n)
{
    if(n==0||n==1)
    return 1;
    else
    {
        if(table[n]==-1)
        table[n]=n*fact(n-1);
        return table[n];
    }

}
int main()
{
    int n , i;
    printf("Enter the value: ");
    scanf("%d" , &n);
    for(i=0;i<500;i++)
    table[i]=-1;
    printf("the factorial is %d" , fact(n));
    return 0;
}