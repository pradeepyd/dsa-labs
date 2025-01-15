#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *First, *last = NULL;
struct SLL *create_node(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (NewNode != NULL)
    {
        NewNode->data = element;
        NewNode->next = NULL;
    }
    return NewNode;
}

void insert_at_beginning(int element)
{
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else
    {
        if (First == NULL)
            First = last = NewNode;
        else
        {
            NewNode->next = First;
            First = NewNode;
        }
    }
}

void display()
{
    struct SLL *temp = First;
    if (First == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        do
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        } while (temp != NULL);
        printf("NULL\n");
    }
}

void insert_at_end(int element)
{
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else
    {
        if (First == NULL)
            First = last = NewNode;
        else
        {
            last->next = NewNode;
            last = NewNode;
        }
    }
}

void insert_at_position(int element, int position)
{
    struct SLL *NewNode = create_node(element);
    if (NewNode == NULL)
    {
        printf("memory allocation failed\n");
    }
    if (position == 1)
    {
        NewNode->next = First;
        First = NewNode;
        printf("insert at begining");
    }
    else
    {
        if (First == NULL)
            First = last = NewNode;
        else
        {
            struct SLL *temp = First ;
            for(int i = 1; i<position-1;i++){
                temp = temp->next;
            }
            NewNode->next= temp->next;
            temp->next = NewNode;
            
        }
    }
}

void delete_at_beginning(){

        if(First == NULL){
            printf("list is empty");
        }
        else if(First -> next == NULL){
            struct SLL *temp = First;
            First = last = NULL;
            free(temp);
        }
        else{
            struct SLL *temp = First;
            First = First -> next;
            free(temp);
        }
    }


void delete_at_end(){
    if(First == NULL){
            printf("list is empty");
        }
        else if(First -> next == NULL){
            struct SLL *temp = First;
            First = last = NULL;
            free(temp);
        }
        else{
            struct SLL *temp = First;
            while (temp ->next != last)
            {
                temp = temp -> next;
            }
            
            last = temp;
            temp = last ->next;
            printf("%d is going to be deleted\n",temp->data);
            free(temp);
            last->next = NULL;
        }
}

void search(int key){
     int flag =0;
     
     if(First == NULL){
        printf("list is empty");
     }
     else{
        struct SLL *temp = First;
        do{
            if(key == temp -> data ){
                flag = 1;
                printf("element found");
            }
            temp = temp -> next;
        }while(temp != NULL);
        if(flag == 0){
            printf("element not found");
        }
     }
}
int main()
{
    insert_at_beginning(100);
    display();
    insert_at_beginning(200);
    display();
    insert_at_end(1000);
    display();
    insert_at_position(300,2);
    display();
    // delete_at_beginning(100);
    // display();
    // delete_at_end();
    // display();
    search(300);
    display();
    return 0;
}