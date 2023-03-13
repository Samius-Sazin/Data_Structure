#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

void print_array(node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->link;
    }
}

node* add_node_end(node *head, int new_data)
{
    node *temp = malloc(sizeof(node));
    temp->data = new_data;
    temp->link = NULL;
    head->link = temp;
    return temp;
}

node* reverse(node *head)
{
    node *prev = NULL, *next = NULL;

    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    return prev;
    
    /*At last step next will be NULL, 
    then head = next so head also be NULL,
    But prev will point to the first node after reversed.so return prev
    */
}

int main()
{
    node *head = malloc(sizeof(node));
    head->data = 10;
    head->link = NULL;

    node *ptr = head;
    ptr = add_node_end(ptr, 20);
    ptr = add_node_end(ptr, 30);
    ptr = add_node_end(ptr, 40);

    head = reverse(head);

    print_array(head);
    return 0;
}
