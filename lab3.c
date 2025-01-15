#include <stdio.h>
#define MAX 5
struct CircularQueue
{
    int front;
    int rear;
    int data[MAX];
};
 typedef struct CircularQueue CQ;

 void enqueue(CQ *Q, int element){
    if(Q->front == (Q->rear+1)%MAX){
        printf("Queue is full\n");
    }else{
        Q->data[Q->rear] = element;
        Q->rear = (Q->rear + 1)%MAX;
        printf("%d was ENQUEUED!\n",element);
    }
 }

 int dequeue(CQ *Q){
    if (Q->front == Q->rear){
        printf("Queue is empty\n");
        return -1;
    }else
        {
        int element = Q->data[Q->front];
        Q->front = (Q->front + 1)%MAX;
        return element;
    }
 }
 int main(){
    int choice, element;
    CQ Q = {0,0};
    do
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.EXIT\n");
        printf("Choice?");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Element to be Enqueue?");
            scanf("%d",&element);
            enqueue(&Q,element);
            break;
        case 2:
            element = dequeue(&Q);
            if(element != -1){
                printf("%d was DEQUEUED\n",element);
            }
            break;
        case 3:
            printf("bye bye");
            break;

        default:
            printf("Enter 1 , 2 or 3 only!\n");
            break;
        }
    } while (choice!=3);
   return 0; 
 }