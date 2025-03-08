#include<stdio.h>
void tower(int n,char src,char tmp,char dest){
    if (n<=0){
        printf("Illegal entry\n");
    }
    else if(n == 1){
        printf("Move DISC 1 from %c to %c\n",src,dest);
    }
    else{
        tower(n-1,src,dest,tmp);
        printf("move DISC %d from %c to %c\n", n, src,dest);
        
        tower(n-1,tmp,src,dest);
    }
}
int main(){
    int n;
    char a,b,c;
    printf("Enter the number of DISC:");
    scanf("%d",&n);
    printf("The TOWER OF HANOI of %d DISC:\n",n);
    tower(n,'a','b','c');
    return 0;
    
}