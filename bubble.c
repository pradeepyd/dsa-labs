#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void buble_sort(int A[], int n){
    int i ,j ,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j]> A[j+1]){
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]= temp;
            }
        }
    }
}
void display(int A[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    int i ,n ,A[100001];
    clock_t start,end;
    srand(time(NULL));
    printf("How much n?");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        A[i] = rand();
    }
    // display(A,n);
    start = clock();

    buble_sort(A,n);
    end = clock();
    // 100display(A,n);
    printf("Time = %f seconds\n",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}