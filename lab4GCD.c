#include<stdio.h>

int gcd(int a , int b){
    if (b == 0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int a ,b ,gcdvalue;
    printf("enter two numbers:");
    scanf("%d %d",&a,&b);
    gcdvalue = gcd(a,b);
    printf("the gcd is %d",gcdvalue);
    return 0 ;
}