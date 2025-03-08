#include <stdio.h>
#include <stdbool.h>
#include <string.h> // to use strlen

#define MAX 50

struct stack
{
    int TOS;
    char Data[MAX];
};

// stack full xa ki xaina
int isFull(struct stack *s)
{
    if (s->TOS == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// stack empty xa ki xaina
int isEmpty(struct stack *s)
{
    if (s->TOS == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(struct stack *s, char element) // push garda kei return garnu pardeina so use void
{
    if (isFull(s))
    {
        printf("stack overflow!!!");
    }
    else
    {
        s->Data[++s->TOS] = element; // push garda jaile pani suruma TOS increase garney
    }
}

int pop(struct stack *s) // pop ma void support garena,why?  => pop le  popped value lai return garnu parxa
{
    if (isEmpty(s))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        return s->Data[s->TOS--]; // pop garda jaile last ma tos increase garney
    }
}

int calculation(int op1, int op2, char operator)
{
    int result;
    switch (operator)
    {
    case '+':
        result = op2 + op1;
        break;
    case '-':
        result = op2 - op1;
        break;
    case '*':
        result = op2 * op1;
        break;
    case '/':
        if (op1 == 0)
        {
            printf("division by 0 is not allowed\n");
            return -1;
        }
        result = op2 / op1;
        break;
    default:
        printf("please enter correct operator!!");
        return -1;
    }
    return result;
}

int main()
{
    struct stack s;
    s.TOS = -1; // Initialize stack
    char input[MAX];
    int op1, op2, result;

    printf("Enter a postfix expression: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++)
    { // expression ko length vanda kam hun jel samma apply for loop
        if (operator(input[i]))
        {

            op1 = pop(&s); // &s means address of the stack variable
            op2 = pop(&s);

            result = calculation(op1, op2, input[i]);
            push(&s, result);
        }
        else
        {
            // mathi input char ma leko xa not in int so use ascii
            // ascii value of 0 = 48 , 5 = 53
            int operand = input[i] - '0';
            push(&s, operand);
        }
    }

    printf("result : %d\n", pop(&s));
    return 0;
}