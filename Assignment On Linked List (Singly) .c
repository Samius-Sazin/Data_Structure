/*
Operations -
For Question 1:
Function 1: Insert Node At The Last position
Function 2: Delete Node From Middle Position
Function 3: Count Nodes

For Question 2:
Function 4: Find a node and print its data, then delete the node and then insert a new node at its position

For Question 3:
Function 5: Delete (n-1)th position Node
Function 6: Find Node With Given Data & Insert a new node at this Position

Function 7: Print Nodes
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

/*Function-1*/ node* Add_Node_Last(node *head);
/*Function-2*/ void Delete_Mid_Node(node *head);
/*Function-3*/ void Count_Nodes(node *head);
/*Function-4*/ node* FindNode_Showdata_Deleteit_CreateNewNodeAtThePosition(node *head);
/*Function-5*/ node* Delete_Nminus1_Position_Node(node *head);
/*Function-6*/ node* FindNode_WithGivenPOsition_InsertNodeAtThisPosition(node *head);
/*Function-7*/ void Print_Nodes(node *head);

int main()
{
    node *HEAD = NULL;
    int choice;
    while(1)
    {
        printf("1. Add Node at The Last Position\n");
        printf("2. Delete Node From Mid Position\n");
        printf("3. Count Nodes\n");
        printf("4. Find a Node and Print the Data Then Delete the Node Create a New Node At its Position\n");
        printf("5. Delete (n-1)th position Node\n");
        printf("6. Find a Node With Data & Insert a New Node at This Position\n");
        printf("7. Print Nodes\n");
        printf("8. Break\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);

        if(choice == 1) HEAD = Add_Node_Last(HEAD);
        else if(choice == 2) Delete_Mid_Node(HEAD);
        else if(choice == 3) Count_Nodes(HEAD);
        else if(choice == 4) HEAD = FindNode_Showdata_Deleteit_CreateNewNodeAtThePosition(HEAD);
        else if(choice == 5) HEAD = Delete_Nminus1_Position_Node(HEAD);
        else if(choice == 6) HEAD = FindNode_WithGivenPOsition_InsertNodeAtThisPosition(HEAD);
        else if(choice == 7) Print_Nodes(HEAD);
        else if(choice == 8) break;
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

node* FindNode_Showdata_Deleteit_CreateNewNodeAtThePosition(node *head)
{
    node *ptr = head, *temp;
    int position;
    printf("Enter a valid position : ");
    scanf("%d",&position);
    if(position = 1)
    {
        printf("Data At position 1 = %d\n",ptr->data);
        //delete the node
        head = head -> next;
        free(ptr);
        ptr = NULL;
        printf("This Node has been Deleted\n");
        //Create a new Node at this Position
        printf("A new node is creating at this position\n");
        int value;
        printf("Enter new Node's Data : ");
        scanf("%d",&value);
        temp = (node*)malloc(sizeof(node));
        temp -> data = value;
        temp -> next = head;
        printf("New Node has beeen Adeed Successfuly\n\n");
        return temp;
    }

    else
    {
        for(int i=0; i<position-2; i++)
        {
            ptr = ptr -> next;
        }
        printf("Data At position %d = %d\n",position, ptr->next->data);
        //Delete the node
        temp = ptr -> next;
        ptr -> next = temp -> next;
        free(temp);
        temp = NULL;
        printf("This Node has been Deleted\n");
        //Create a new Node at this Position
        printf("A new node is creating at this position\n");
        int value;
        printf("Enter new Node's Data : ");
        scanf("%d",&value);
        temp = (node*)malloc(sizeof(node));
        temp -> data = value;
        temp -> next = ptr -> next;
        ptr -> next = temp;
        printf("New Node has beeen Adeed Successfuly\n\n");
        return head;
    }
}

node* Delete_Nminus1_Position_Node(node* head)
{
    node *ptr = head, *temp = head;
    int position, Total_NOde=0;
    printf("Enter position : ");
    scanf("%d",&position);
    while (temp != NULL)
    {
        Total_NOde++;
        temp = temp -> next;
    }
    if(position>2 && position<Total_NOde +2)
    {
        for(int i=0; i<position-2; i++)
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        printf("%d is deleted\n\n",ptr->data);
        temp -> next = ptr -> next;
        free(ptr);
        ptr = NULL;
        return head;
    }
    else if(position == 2)
    {
        printf("%d is deleted\n\n",head->data);
        head = head->next;
        free(ptr);
        ptr = NULL;
        return head;
    }
    else
    {
        printf("Wrong Position\n\n");
        return head;
    }
}

node* FindNode_WithGivenPOsition_InsertNodeAtThisPosition(node *head)
{
    node *ptr = head, *temp;
    int find, position=0;
    printf("Enter a Valid Value That You Want to Find : ");
    scanf("%d",&find);
    while (ptr->data != find)
    {
        position++;
        ptr = ptr -> next;
    }
    position+=1;

    printf("The Value You are Searching That Fount at Position %d\n",position);
    printf("Now a New Node is Going to Add at This Position\n");
    printf("Enter New Node Value : ");
    int value;
    scanf("%d",&value);

    temp = (node*)malloc(sizeof(value));
    temp -> data = value;
    temp -> next = NULL;
    ptr = head;

    if(position == 1)
    {
        temp -> next = head;
        printf("Insertion Complete\n\n");
        return temp;
    }
    else
    {
        for(int i=0; i<position-2; i++)
        {
            ptr = ptr -> next;
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
        printf("Insertion Complete\n\n");
        return head;
    }
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
