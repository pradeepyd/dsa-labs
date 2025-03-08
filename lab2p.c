#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define max 100

struct stack
{
    int TOS;
    int Data[max];
};

int isfull(struct stack *s)
{
    return s->TOS == max - 1 ? 1 : 0;
}

int isempty(struct stack *s)
{
    return s->TOS == -1 ? 1 : 0;
}

bool operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

void push(struct stack *s, int element)
{
    //printf("%d",element);
    s->TOS += 1;
    s->Data[s->TOS] = element;
}

int pop(struct stack *s)
{
    int result = s->Data[s->TOS];
    s->TOS -= 1;
    
    return result;
}

int main()
{
    int result;
    int op1;
    int op2;
    int a = 0;
    char in[100];
    char data[100];
    struct stack s = {-1};
    printf("Enter the Expression: ");
    gets(data);

    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] != ' ')
        {
            in[a++] = data[i];
        }
    }
     in[a] = '\0'; 
    strcpy(data, in);
    
    for (int i = 0; i < strlen(data); i++)
    {
        if (operator(data[i]))
        {
            op1 = pop(&s);
            op2 = pop(&s);
            if (data[i] == '+')
            {
                result = (op2 + op1);
                
            }
            if (data[i] == '-')
            {
                result = (op2 - op1);
               
            }
            if (data[i] == '*')
            {
                result = (op2 * op1);
                
            }
            if (data[i] == '/')
            {
                result = (op2 / op1);
            }
           
            push(&s, result);
        }
        else
        {
            result=data[i]-'0';
            push(&s, result);
        }
    }
    printf("Postfix Result is: %d",pop(&s));
    return 0;
}