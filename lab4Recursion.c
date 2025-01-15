#include<stdio.h>
long long int table[1005];
long long int fibo(int n) {
    if(n == 1 || n==2){
        return 1;
    }
    else{
        if(table[n] == -1){
            table[n] = fibo(n-1) + fibo(n-2);
        }
        return table[n];
    }
}

int main(){
    long int n;
    for(int i=1; i<1005;i++){
        table[i]= -1;
    }
    printf("enter n:");
    scanf("%d",&n);
    printf("Answer is %lld\n",fibo(n));
    return 0;
}