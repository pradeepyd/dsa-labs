#include <stdio.h>
#include <string.h>
#define MAX 5
#define true 1
#define false 0

struct Person {
    int id;
    char name[50];
    int age;
};

struct Stack {
    int TOS;
    struct Person DATA[MAX];
};

int isFull(struct Stack *S) {
    return S->TOS == MAX - 1 ? true : false;
}

int isEmpty(struct Stack *S) {
    return S->TOS == -1 ? true : false;
}

void push(struct Stack *S, struct Person element) {
    if (isFull(S)) {
        printf("Stack Overflow!!\n");
    } else {
        S->TOS += 1;
        S->DATA[S->TOS] = element;
        printf("Person with ID %d WAS PUSHED!!\n", element.id);
    }
}

struct Person pop(struct Stack *S) {
    struct Person emptyPerson = {-1, "", -1};
    if (isEmpty(S)) {
        printf("Stack Underflow!!\n");
        return emptyPerson;
    } else {
        struct Person element = S->DATA[S->TOS];
        S->TOS -= 1;
        return element;
    }
}

// Main function
int main() {
    int choice;
    struct Stack S = {-1};
    struct Person tempPerson;
    
    do {
        printf("\n1. PUSH\n2. POP\n3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &tempPerson.id);
            printf("Enter Name: ");
            scanf("%s", tempPerson.name);
            printf("Enter Age: ");
            scanf("%d", &tempPerson.age);
            push(&S, tempPerson);
            break;

        case 2:
            tempPerson = pop(&S);
            if (tempPerson.id != -1) {
                printf("Person Popped -> ID: %d, Name: %s, Age: %d\n",
                       tempPerson.id, tempPerson.name, tempPerson.age);
            }
            break;

        case 3:
            printf("BYE-BYE!!\n");
            break;
        
        default:
            printf("Please enter 1, 2, or 3 only!\n");
            break;
        }
    } while (choice != 3);
    
    return 0;
}
