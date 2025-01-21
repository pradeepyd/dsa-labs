#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void max_heapify(int A[],int i,int n){
    int l=2*i, r=2*i+1,largest=i,temp;
    if(l<=n && A[l]> A[largest])
        largest = l;
    if(r<=n && A[r] > A[largest])
        largest =r;
    if(largest != i){
        temp = A[largest];
        A[largest]= A[i];
        A[i] = temp;
        max_heapify(A,largest,n);
    }
}

void build_max_heap(int A[], int n){
    int i;
    for(i=n/2;i>=1;i--){
        max_heapify(A, i , n);
    }
}

void heap_sort(int A[], int n){
    int i,temp;
    build_max_heap(A,n);
    for(i=n;i>=2;i--){
        temp=A[1];
        A[1]= A[i];
        A[i] = temp;
        n = n-1;
        max_heapify(A,1,n);
    }
}

void display(int A[],int n){
    int i;
    for(i=1;i<=n;i++){
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
    for(i=1;i<=n;i++){
        A[i] = rand();
    }
    // display(A,n);
    start = clock();

    heap_sort(A,n);
    end = clock();
    // display(A,n);
    printf("Time = %f seconds\n",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}