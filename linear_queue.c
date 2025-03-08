#include<stdio.h>
#define MAX 5
struct Queue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
void Enque(struct Queue *Q , int element )
{
    if(Q->REAR==MAX-1)
    printf("QUEUE IS FULL");
    else
    {
       Q->REAR+=1;
       Q->DATA[Q->REAR]=element;
    }

}
int Deque(struct Queue *Q )
{
    int element;
    if(Q->REAR<Q->FRONT)
    {
    printf("QUEUE IS EMPTY\n");
    }
    else
    {
        element=Q->DATA[Q->FRONT];
        Q->FRONT+=1;

    }
            return element;

    
}
int main()
{
    int choice;
    int input;
    struct Queue Q={0,-1};
    while(1)
    {
        printf("1. for Enqueue\n 2. for dequeue\n");
        scanf("%d" , &choice);
        if(choice==1)
        {
            printf("Enter the value: ");
            scanf("%d" , &input);
            Enque(&Q,input);
        }
        if(choice==2)
        {
            int output=Deque(&Q);
            printf("%d\n" , output);
        }


    }
    return 0;
}