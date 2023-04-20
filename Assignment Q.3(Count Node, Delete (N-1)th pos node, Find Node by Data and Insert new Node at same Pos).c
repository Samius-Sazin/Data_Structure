#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

//Function that count number of nodes
int Count_Nodes(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head -> next;
    }
    printf("Total Nodes = %d\n\n",count);
    return count;
}

//Function that delete (N-1)th position Node
void delete_Nminus1_Node(node *head, int n)
{
    node *ptr = head, *temp;
    for(int i=0; i<n-1; i++)
    {
        temp = ptr;
        ptr = ptr -> next;
    }
    temp->next = ptr->next;
    free(ptr);
    ptr = NULL;
}

//Function that find a node by given data and inser a new node just at this position
void find_node(node **head, int value)
{
    node *ptr = *head;
    int pos = 0;
    while (ptr->data != value)
    {
        pos++;
        ptr = ptr -> next;
        if(ptr == NULL)
        {
            printf("%d is not available in Linked List\n\n",value);
            return;
        }
    }
    pos+=1;
    printf("%d is found at position %d\n\n",value, pos);

    printf("Enter Data to inser at Position %d : ",pos);
    scanf("%d",&value);
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = value;
    if(pos == 1)
    {
        temp -> next = *head;
        *head = temp;
    }
    else
    {
        ptr = *head;
        for(int i=0; i<pos-2; i++)
        {
            ptr = ptr -> next;
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
    printf("%d insert at position %d Successffull\n\n",value, pos);
}


//Function to insert a new node at the end of a linked list
void insert(node **head, int new_data)
{
    node *ptr = *head;
    node *temp = (node*)malloc(sizeof(node));
    temp -> data = new_data;
    temp -> next = NULL;

    if(ptr == NULL)
    {
        ptr = temp;
        *head = ptr;
        return;
    }
    while(ptr->next != NULL)
    {
        ptr = ptr -> next;
    }
    ptr -> next = temp;
    return;
}

//Function that Print the full Linked List
void Print_Nodes(node *head)
{
    while (head->next != NULL)
    {
        printf("%d --> ",head -> data);
        head = head -> next;
    }
    printf("%d\n\n",head -> data);
}

int main()
{
    int pos, value, N;
    node *HEAD = NULL;

    insert(&HEAD, 2);
    insert(&HEAD, 8);
    insert(&HEAD, 14);
    insert(&HEAD, 18);
    insert(&HEAD, 25);

    printf("Linked List : ");
    Print_Nodes(HEAD);
    N = Count_Nodes(HEAD);

    delete_Nminus1_Node(HEAD, N-1);
    printf("After delete (N-1)th position Node The L.List : ");
    Print_Nodes(HEAD);

    printf("Enter Data to find its Position : ");
    scanf("%d",&value);
    find_node(&HEAD, value);

    printf("Final Linked List : ");
    Print_Nodes(HEAD);

    return 0;
}
