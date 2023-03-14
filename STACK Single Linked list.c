#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

struct node *head = NULL;
void push();
void pop();
void print();

int main()
{
    int choice, value;

    while(1)
    {
        printf("**** 1-PUSH  2-POP  3-DISPLAY  4-EXIT ****\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        if(choice == 1) push();
        else if(choice == 2) pop();
        else if(choice == 3) print();
        else if(choice == 4) break;
        else printf("Wrong selection\n");
    }
}

void push()
{
    int value;
    printf("Enter value that you want to PUSH : ");
    scanf("%d",&value);

    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    if(head == NULL) temp->next = NULL;
    else temp->next = head;
    head = temp;
    temp = NULL;
    printf("Insertion Successfull\n");
}

void pop()
{
    if(head == NULL) printf("Stack is Empty\n");
    else
    {
        printf("%d will be deleted\n",head->data);
        struct node *ptr = head;
        head = head->next;
        free(ptr);
        ptr = NULL;
    }
}

void print()
{
    if(head == NULL) printf("Stack is empty\n");
    else
    {
        struct node *ptr = head;
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}
