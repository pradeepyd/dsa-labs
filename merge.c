#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int A[], int l, int m,int r){
    int i=l,j=m,k=l,B[100000];
    while (i<m && j<=r)
    {
        if(A[i]<A[j])
            B[k++]= A[i++];
        else
            B[k++]= A[j++];
    }
    for(;i<m;i++,k++)
        B[k] = A[i];
    for(;j<=r;j++,k++)
        B[k]=A[j];
    for(k=l;k<=r; k++)
        A[k]=B[k];
    
}

void merge_sort(int A[], int l,int r){
    int m;
    if(l<r){
        m = (l+r)/2;
        merge_sort(A,l,m);
        merge_sort(A,m+1,r);
        merge(A,l, m+1,r);
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

    merge_sort(A,0,n-1);
    end = clock();
    // 100display(A,n);
    printf("Time = %f seconds\n",(float)(end-start)/CLOCKS_PER_SEC);
    return 0;
}