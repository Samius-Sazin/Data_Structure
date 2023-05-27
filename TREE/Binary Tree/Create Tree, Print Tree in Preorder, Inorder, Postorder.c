/*
          1         --Level 0

      2       3     --Level 1

   4     5       6  --Level 2

       7   8        --Level 3

Input  : 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 -1
Preorder : 1 2 4 5 7 8 3 6
Inorder : 4 2 7 5 8 1 3 6
Postorder : 4 7 8 5 2 6 3 1
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node* Create_tree();
void print_preorder(node *root);
void print_inorder(node *root);
void print_postorder(node *root);

int main()
{
    node *ROOT = NULL;
    ROOT = Create_tree();
    printf("Preorder : ");
    print_preorder(ROOT);

    printf("\nInorder : ");
    print_inorder(ROOT);

    printf("\nPostorder : ");
    print_postorder(ROOT);

    return 0;
}

node* Create_tree()
{
    int value;
    scanf("%d",&value);
    if(value == -1) return NULL;

    node *temp = (node*)malloc(sizeof(node));
    temp -> data = value;
    temp -> left = Create_tree();
    temp -> right = Create_tree();

    return temp;
}

//Funtion that print in Preorder
void print_preorder(node *root)
{
    if(root == NULL) return;

    printf("%d ",root->data);
    print_preorder(root -> left);
    print_preorder(root -> right);
}

//Funtion that print in Inorder
void print_inorder(node *root)
{
    if(root == NULL) return;

    print_inorder(root -> left);
    printf("%d ",root->data);
    print_inorder(root -> right);
}

//Funtion that print in Postorder
void print_postorder(node *root)
{
    if(root == NULL) return;

    print_postorder(root -> left);
    print_postorder(root -> right);
    printf("%d ",root->data);
}
