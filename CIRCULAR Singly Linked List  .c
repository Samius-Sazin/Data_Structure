#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node* count(node *tail);
void print(node *tail);

node* create_first_node();
node* add_second_node(node *tail);

void Add_FRONT(node *tail);
node* Add_LAST(node *tail);
node* Add_MID(node *tail);

void Delete_FIRST(node *tail);
node* Delete_LAST(node *tail);
node* Delete_MIDDLE();

void main()
{
    char choice;
    int choose;
    node *TAIL = NULL;
    printf("**** CIRCULAR SINGLY LINKED LIST ****\n\n");

    printf("Enter 'Y' for create FIRST node : ");
    scanf("%c",&choice);
    if(choice == 'Y' || choice == 'y' )
    {
        TAIL = create_first_node();
    }

    printf("Enter 'Y' for create SECOND node : ");
    scanf("\n%c",&choice);
    if(choice == 'Y' || choice == 'y')
    {
        TAIL = add_second_node(TAIL);
    }

    if(TAIL != TAIL->next)
    {
        while(1 && TAIL != NULL)
        {
            printf("1. Add node at FRONT\n2.. Add node at LAST\n3. Add node at MIDDLE\n");
            printf("4.. Delete FIRST Node\n5. Delete LAST Node\n6.. Delete MIDDLE Node\n");
            printf("7. PRINT Node\n8.. EXIT\n");
            printf("----Enter your choice : \n");
            scanf("%d",&choose);
            if(choose == 1) Add_FRONT(TAIL);
            else if(choose == 2) TAIL = Add_LAST(TAIL);
            else if(choose == 3) TAIL = Add_MID(TAIL);
            else if(choose == 4) Delete_FIRST(TAIL);
            else if(choose == 5) TAIL = Delete_LAST(TAIL);
            else if(choose == 6) TAIL = Delete_MIDDLE(TAIL);
            else if(choose ==7) print(TAIL);
            else if(choose == 8) break;
            else printf("Enter valid number\n\n");
        }
    }
}

node* count(node *tail)
{
    int count = 0;
    node *ptr = tail->next;
    do
    {
        count++;
        ptr = ptr->next;
    }
    while(ptr != tail->next);
    return count;
}

void print(node *tail)
{
    node *ptr = tail->next;
    printf("\n");
    do
    {
        printf("%d --> ",ptr->data);
        ptr = ptr->next;
    }
    while(ptr != tail->next);
    printf("%d(1st node data)\n\n",tail->next->data);
}

node* create_first_node()
{
    int value;
    printf("Enter first node's value : ");
    scanf("%d",&value);

    node *tail = (node*)malloc(sizeof(node));
    tail->data = value;
    tail->next = tail;
    return tail;
}

node* add_second_node(node *tail)
{
    if(tail == NULL) printf("ERROR!!\nFirst node is not created.\n");
    else
    {
        int value;
        printf("Enter second node's value : ");
        scanf("%d",&value);

        node* temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = NULL;
        tail->next = temp;
        temp->next = tail;
        tail = temp;
        return tail;
    }
}

void Add_FRONT(node *tail)
{
    int value;
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter Node's VALUE : ");
    scanf("%d",&value);
    temp->data = value;
    temp->next = tail->next;
    tail->next = temp;
    printf("Successfully Added\n\n");
}

node* Add_LAST(node *tail)
{
    int value;
    printf("Enter node's value : ");
    scanf("%d",&value);
    node *temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = tail->next;
    tail->next = temp;
    printf("Successfully Added\n\n");
    return temp; /*
                   or
                   tail=temp;
                   return tail;
                 */
}

node* Add_MID(node *tail)
{
    int value,pos,c;

    c = count(tail);
    printf("Total node = %d\n",c);

    printf("Enter POSITION : ");
    scanf("%d",&pos);

    if(pos == 1)
    {
        Add_FRONT(tail);
        return tail;
    }
    else if(pos == (c+1))
    {
        tail = Add_LAST(tail);
        return tail;
    }
    else if(pos > (c+1) || pos<1) printf("Enter valid position.\n\n");
    else
    {
        printf("Enter VALUE : ");
        scanf("%d",&value);

        node *ptr = tail->next;
        node *temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = NULL;

        for(int i=0; i<pos-2; i++)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        printf("Successfully Added\n\n");
        return tail;
    }
}

void Delete_FIRST(node *tail)
{
    node *ptr = tail->next;
    printf("%d is deleted\n\n",ptr->data);

    tail->next = ptr->next;
    free(ptr);
    ptr = NULL;
}

node* Delete_LAST(node *tail)
{
    node *ptr = tail->next;
    printf("%d is deleted.\n\n",tail->data);
    while(ptr->next != tail)
    {
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = NULL;
    return ptr;
}

node* Delete_MIDDLE(node *tail)
{
    int pos,c;
    c = count(tail);
    printf("Total node = %d\n",c);
    printf("Enter position to delete : ");
    scanf("%d",&pos);
    if(pos == 1)
    {
        Delete_FIRST(tail);
        return tail;
    }
    else if(pos == c)
    {
        tail = Delete_LAST(tail);
        return tail;
    }
    else if(pos>c || pos<1) printf("Enter valid position.\n\n");
    else
    {
        node *ptr2 = tail->next;
        node *ptr1;
        for(int i=0; i<pos-1; i++)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        printf("%d is deleted\n\n",ptr2->data);
        ptr1->next = ptr2->next;
        free(ptr2);
        ptr2 = NULL;
        return tail;
    }
}
