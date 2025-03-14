#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int A[], int n){
    int i ,j ,temp,least,pos;
    for(i=0;i<n;i++){
        least = A[i];
        pos= i;
        for(j=i+1;j<n;j++){
            if(A[j]<least){
                least = A[j];
                pos= j;
            }
        }
        if(i != pos){
            temp = A[i];
            A[i]= A[pos];
            A[pos]= temp;
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

    selection_sort(A,n);
    end = clock();
    // 100display(A,n);
    printf("Time = %f seconds\n",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}