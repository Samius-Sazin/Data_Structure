#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

struct node *head = NULL;
struct node *ptr = NULL;

void insert();//enqueue
void delet();//dequeue
void print();

int main()
{
    int choice;

    printf("**** QUEUE in SINGLY Linked List ****\n");

    while(1)
    {
        printf("1- INSERT\n2- DELETE\n3- PRINT\n4- EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        if(choice == 1) insert();
        else if(choice == 2) delet();
        else if(choice == 3) print();
        else if(choice == 4)
        {
            printf("QUEUE operation exit.\n");
            break;
        }
        else printf("Wrong selection. Select again\n");
    }
}

void insert()
{
    int value;
    printf("Enter the value : ");
    scanf("%d",&value);


    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    if(head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else if(head->next == NULL)
    {
        temp->next = NULL;
        head->next = temp;
        ptr = temp;
    }
    else
    {
        temp->next = NULL;
        ptr->next = temp;
        ptr = temp;
    }

    printf("Insertion Successfull...\n\n");
}

void delet() //head will be deleted
{
    printf("\n%d will be deleted\n",head->data);
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    printf("Deletion Successful...\n\n");
}

void print()
{
    if(head == NULL) printf("Queue is empty\n");
    else
    {
        struct node *ptr = head;
        while(ptr != NULL)
        {
            printf("%d --> ",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n\n");
    }
}
