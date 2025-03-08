#include <stdio.h>
#define MAX 5

struct Stack
{
    int TOS;
    int DATA[MAX];
};

int isFull(struct Stack *S)
{
    /*
    if(S->TOS == MAX-1)
        return true;
    else
        return false;
    */
   return S->TOS == MAX-1 ? 1 : 0;
}
int isEmpty(struct Stack *S)
{
    /*
    if(S->TOS == -1)
        return true;
    else
        return false;
    */
   return S->TOS == -1 ? 1:0;
}
void push(struct Stack *S, int element)
{
    if(S->TOS == MAX-1)
        printf("Stack Overflow!!\n");
    else
    {
        S->TOS += 1;
        S->DATA[S->TOS] = element;
        printf("%d WAS PUSHED!!\n",element);
    }
}
int pop(struct Stack *S)
{
    int element;
    if(S->TOS == -1)
    {
        printf("Stack Underflow!!");
        return -1;
    }
    else
    {
        element = S->DATA[S->TOS];
        S->TOS -= 1;
        return element;
    }
}
int main()
{
    int data, choice;
    struct Stack S = {-1};
    do
    {
        printf("1.PUSH\n2.POP\n3.EXIT\n");
        printf("Enter your choice ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Element to PUSH? ");
            scanf("%d",&data);
            push(&S, data);
            break;

        case 2:
            data = pop(&S);
            if(data != -1)
                printf("%d WAS POPPED!!",data);
            break;

        case 3:
            printf("BYE-BYE!!\n");
            break;
        
        default:
            printf("Please enter 1,2 or 3 only!\n");
            break;
        }
    } while (choice!=3);
    
}