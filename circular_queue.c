#include<stdio.h>
#define MAX 5
struct CQueue
{
    int FRONT;
    int REAR;
    int DATA[MAX];
};
void Enque(struct CQueue *Q , int element )
{
    if(Q->FRONT==(Q->REAR+1)%MAX)
    {
    printf("QUEUE IS FULL");
    }
    else
    {
    Q->DATA[Q->REAR]=element;
       Q->REAR=(Q->REAR+1)%MAX;
    }

}
int Deque(struct CQueue *Q )
{
    int element;
    if(Q->REAR==Q->FRONT)
    printf("QUEUE IS EMPTY");
    else
    {
        element=Q->DATA[Q->FRONT];
        Q->FRONT=(Q->FRONT+1)%MAX;

    }
            return element;

    
}
int main()
{
    int choice;
    int input;
    struct CQueue Q={0,0};
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