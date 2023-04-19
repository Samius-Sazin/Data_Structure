#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node* Add_Node_Last(node *head);
void Delete_Mid_Node(node *head);
void Count_Nodes(node *head);

void Print_Nodes(node *head);

int main()
{
    node *HEAD = NULL;
    int choice;
    while(1)
    {
        printf("1. Add Node at The Last Position\n");
        printf("2. Delete Node From Mid Position\n");
        printf("3. Count Nodes\n");
        printf("4. Print Nodes\n");
        printf("5. Break\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        if(choice == 1) HEAD = Add_Node_Last(HEAD);
        else if(choice == 2) Delete_Mid_Node(HEAD);
        else if(choice == 3) Count_Nodes(HEAD);
        else if(choice == 4) Print_Nodes(HEAD);
        else if(choice == 5) break;
        else printf("Enter Valid Value\n\n");
    }
    return 0;
}

node* Add_Node_Last(node *head)
{
    int value;
    printf("Enter Value : ");
    scanf("%d",&value);
    node *ptr = head;
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = value;
    temp -> next = NULL;

    if(head == NULL)
    {
        head = temp;
        return head;
    }
    while(ptr->next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    printf("Added Succesfully\n\n");
    return head;
}

void Delete_Mid_Node(node *head)
{
    node *ptr = head, *temp = head;
    int position, total_node = 0;

    while (ptr != NULL)
    {
        total_node++;
        ptr = ptr -> next;
    }
    printf("Enter Position : ");
    scanf("%d",&position);
    ptr = head;

    if(position>1 && position<total_node+1)
    {
        for(int i=0; i<position-1; i++)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        temp -> next = ptr -> next;
        free(ptr);
        ptr = NULL;
        printf("Deleted Successfully\n\n");
    }
    else printf("Wrong Position\n\n");
}

void Count_Nodes(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head -> next;
    }
    printf("Total Nodes = %d\n\n",count);
}

void Print_Nodes(node *head)
{
    while (head->next != NULL)
    {
        printf("%d --> ",head -> data);
        head = head -> next;
    }
    printf("%d\n\n",head -> data);
}
