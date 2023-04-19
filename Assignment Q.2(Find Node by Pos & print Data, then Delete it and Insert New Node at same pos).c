#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

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


//This Function Find an item by Position and Print the data
void find_node(node *head, int pos)
{
    node *ptr = head;
    for(int i=0; i<pos-1; i++)
    {
        ptr = ptr->next;
    }
    printf("Data at Position %d = %d\n\n",pos, ptr->data);
    return;
}


//Function That Delete the Node
void delete_node(node **head, int pos)
{
    node *ptr = *head, *temp = *head;

    if(pos == 1)
    {
        ptr = ptr -> next;
        free(temp);
        temp = NULL;
        *head = ptr;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            ptr = temp;
            temp = temp -> next;
        }
        ptr -> next = temp -> next;
        free(temp);
        temp = NULL;
    }
}

//Function that Create a New Node
void create_node(node **head, int pos, int value)
{
    node *ptr = *head, *temp = (node*)malloc(sizeof(node));
    temp -> data = value;

    if(pos == 1)
    {
        temp -> next = *head;
        *head = temp;
    }
    else
    {
        for(int i=0; i<pos-2; i++)
        {
            ptr = ptr-> next;
        }
        temp->next = ptr->next;
        ptr -> next = temp;
    }
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
    int pos, value;
    node *HEAD = NULL;

    insert(&HEAD, 2);
    insert(&HEAD, 8);
    insert(&HEAD, 14);
    insert(&HEAD, 18);
    insert(&HEAD, 25);

    printf("Linked List : ");
    Print_Nodes(HEAD);

    printf("Enter Position for Further Operations : ");
    scanf("%d",&pos);
    if(pos >= 1 && pos <= 5)
    {
        find_node(HEAD, pos);

        delete_node(&HEAD, pos);
        printf("After Delete %d Position Node L.List : ",pos);
        Print_Nodes(HEAD);

        printf("Enter Data to Add New Node at the Same Position : ");
        scanf("%d",&value);
        create_node(&HEAD, pos, value);

        printf("Final Linked List : ");
        Print_Nodes(HEAD);
    }
    else printf("Wrong Position\n\n");
    return 0;
}
