#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

void print_node(node *p)
{
    int i=0;
    while(p != NULL)
    {
        i++;
        printf("Node Data in pos. %d = %d\n",i,p->data);
        p=p->link;
    }
}

void count_node(node *p)
{
    int count=0;

    while(p != NULL)
    {
        count++;
        p=p->link;
    }
    printf("Number of NODES are = %d\n",count);
}

node* add_node_last_pass_by_value(node *p, int new_data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=new_data;
    temp->link=NULL;
    p->link = temp;
    return temp;
}

node* add_node_last_pass_by_reference(node **p, int new_data)
{
    node *p2 = *p;
    node *temp = (node*)malloc(sizeof(node));
    temp->data = new_data;
    temp->link = NULL;
    p2->link = temp;
    *p=temp;
}

node* add_node_first_pass_by_value(node *head, int new_data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = new_data;
    temp->link = head;
    head = temp;
    return head;
}

node* add_node_first_pass_by_reference(node **head, int new_data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = new_data;
    temp->link = *head;
    *head = temp;
}

void add_node_middle_pass_by_value(node *head, int new_data, int pos)
{
    node *ptr = head;
    node *temp = (node*)malloc(sizeof(node));
    temp->data = new_data;
    temp->link = NULL;

    for(int i=0; i<pos-2; i++)
    {
        ptr=ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;

}

void add_node_middle_pass_by_reference(node **head, int new_data, int pos)
{
    node *ptr = *head;
    node *temp = (node*)malloc(sizeof(node));
    temp->data = new_data;
    temp->link = NULL;

    for(int i=0; i<pos-2; i++)
    {
        ptr=ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;

}

node* delete_first_node(node *head)
{
    node *temp = (node*)malloc(sizeof(node));
    temp = head;
    head = head->link;
    free(temp);
    temp = NULL;
    return head;
}

void delete_last_node_2ptr(node *head)
{
    if(head == NULL) printf("there is no NODE\n");
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *ptr = head, *temp = head;
        while(temp->link != NULL)
        {
            ptr = temp;
            temp = temp->link;
        }
        ptr->link = NULL;
        free(temp);
        temp = NULL;
    }
}

void delete_last_node_1ptr(node *head)
{
    if(head == NULL) printf("No Node\n");
    else if(head->link == NULL)
    {
        free(head);
        head == NULL;
    }
    else
    {
        node *ptr = head;
        while(ptr->link->link != NULL)
        {
            ptr = ptr->link;
        }
        free(ptr->link);
        ptr->link = NULL;
    }
}

/*
void delete_any_mid_node(node *head, int pos)
{
    node *temp = head, *ptr = head;
    for(int i=0; i<pos-1; i++)
    {
        temp = temp->link;
    }
    while(ptr->link != temp)
    {
        ptr = ptr->link;
    }
    ptr->link = temp->link;
    free(temp);
    temp = NULL;
}
*/
void delete_any_mid_node(node *head, int pos)
{
    node *temp = head, *ptr = head;
    for(int i=0; i<pos-1; i++)
    {
        ptr = temp;
        temp = temp->link;
    }

    ptr->link = temp->link;
    free(temp);
    temp = NULL;
}

node* delete_full_single_LL(node *head)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->link;
        free(head);
        head=ptr;
    }
    return head;
}

void reverse_single_LL()
{
}



int main()
{
    node *HEAD = (node*)malloc(sizeof(node));
    HEAD->data = 30;
    HEAD->link = NULL;

    /*
    HEAD = add_node_first_pass_by_value(HEAD,7);
    add_node_first_pass_by_reference(&HEAD,9);
    must add node at the last,then add at first*/

    node *ptr_last = HEAD;
    ptr_last = add_node_last_pass_by_value(ptr_last,40);
    ptr_last = add_node_last_pass_by_value(ptr_last,50);
    add_node_last_pass_by_reference(&ptr_last,60);
    add_node_last_pass_by_reference(&ptr_last,70);

    HEAD = add_node_first_pass_by_value(HEAD,20);
    add_node_first_pass_by_reference(&HEAD,10);

    add_node_middle_pass_by_value(HEAD,55,6);
    node* ptr_mid = HEAD;
    add_node_middle_pass_by_reference(&ptr_mid,65,8);

    add_node_middle_pass_by_value(HEAD,100,10);//adding this at the last

    HEAD = delete_first_node(HEAD);//10 deleted
    //delete_last_node_2ptr(HEAD);
    delete_last_node_1ptr(HEAD);
    delete_any_mid_node(HEAD,3);//40 deleted

    //HEAD = delete_full_single_LL(HEAD);
    if(HEAD == NULL)
        printf("Whole Single Linked List Deleted Successfully\n");

    //reverse_single_LL(HEAD);

    count_node(HEAD);
    print_node(HEAD);
    return 0;
}
