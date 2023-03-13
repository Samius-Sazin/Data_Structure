#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

void print(node *ptr)
{
    int i = 0;
    if(ptr == NULL) printf("Head = NULL - \"NO NODE\"\n");
    while(ptr != NULL)
    {
        i++;
        printf("%d th Node Data = %d\n",i,ptr->data);
        ptr = ptr->next;
    }
}

node* count(node *ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

node* create_first_node(node *head, int new_data)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = new_data;
    temp->next = NULL;
    head = temp;
    return head;
}

void AddMid(node *head, int new_data, int pos)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = new_data;
    temp->next = NULL;

    for(int i=0; i<pos-2; i++)
    {
        head = head->next;
    }
    temp->next = head->next;
    head->next->prev = temp;
    head->next = temp;
    temp->prev = head;
}

node* AddEnd(node *ptr, int new_data)
{
    node *temp = malloc(sizeof(node));
    temp->prev = NULL;
    temp->data = new_data;
    temp->next = NULL;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;

    return temp;
}

void delete_any_node(node *head)
{
    int pos;
    printf("Enter position that you want to delete : ");
    scanf("%d",&pos);

    int c;
    c = count(head);
    if(pos == c)
    {
        node *ptr = head;
        for(int i=0; i<pos-2; i++)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }

    else
    {
        node *temp = head, *ptr = head;
        for(int i=0; i<pos-1; i++)
        {
            ptr=temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        temp = NULL;
    }
}

node* create_full_DLL(node *head)
{
    int n, data, i, m, pos;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);

    if(n==0)
        return head;

    printf("Enter data of NODE 1 : ");
    scanf("%d",&data);
    head = create_first_node(head, data);

    node *ptr = head;
    for(int i=2; i<=n; i++)
    {
        printf("Enter data for NODE %d : ",i);
        scanf("%d",&data);
        ptr = AddEnd(ptr, data);
    }

    printf("If you want to add node between 2 nodes then enter 1 : ");
    scanf("%d",&m);
    if(m==1)
    {
        printf("Enter data : ");
        scanf("%d",&data);
        printf("Enter Position : ");
        i=0;
        do
        {
            i++;
            if(i>1)
            {
                printf("Invalid Position\n");
                printf("Enter Position : ");
            }
            scanf("%d",&pos);
        }
        while(pos<1 || pos>n);
        printf("\n\n");
        AddMid(head, data, pos);
    }
    return head;
}


node* delete_node(node *head)
{
    int choose;
    if(head == NULL)
    {
        printf("There is no node to delete.\n");
        return head;
    }

    printf("Press 1 for delete 1st node : ");
    scanf("%d",&choose);
    if(choose == 1)
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
            return head;
        }

        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return head;
    }

    printf("Press 1 for delete any node : ");
    scanf("%d",&choose);
    if(choose == 1)
    {
        delete_any_node(head);
        return head;
    }
}

node* reverse_node(node *head)
{
    node *ptr1 = head;
    node *ptr2 = head->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2!= NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;

}

int main()
{
    int choose;
    node *head = NULL;

    head = create_full_DLL(head);

    printf("Press 1 for delete node : ");
    scanf("%d",&choose);
    if(choose == 1) head = delete_node(head);

    head = reverse_node(head);


    printf("\n\n");
    print(head);
    return 0;
}
