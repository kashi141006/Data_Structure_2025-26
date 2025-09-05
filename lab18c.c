#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
    char name[100];
};
struct node *createNode(int value,char a[100])
{        
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
     
    strcpy(newNode->name,a); 
    newNode->lptr = NULL;
    newNode->rptr = NULL;     
    return newNode;
}

struct node *insertNode(struct node *root, int value,char a[100])
{

    if (root == NULL)
    {
        root = createNode(value,a);
    }
    if (root->info > value)
    {
        root->lptr = insertNode(root->lptr, value,a);
    }
    if (root->info < value)
    {
        root->rptr = insertNode(root->rptr, value,a);
    }

    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lptr);
    printf("%d %s", root->info,root->name);
    inorder(root->rptr);
}
 
struct node *search(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("not found\n");
        return root;
    }

    if (value == root->info)
    {
        printf("found\n");
        printf("%d\n", root->info);
    }
    if (root->info > value)
    {
        return search(root->lptr, value);
    }
    if (root->info < value)
    {
        return search(root->rptr, value);
    }
    return root;
}
 
 

int main()
{
    struct node *root = NULL;
    int n, x, choice;
    char a[100];

    while (1)
    {
        printf("1.Insert node\n");
        printf("2.inorder traversel\n");
         
         printf("3.search\n");
        // printf("6.delete\n");
        // printf("7.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            
                printf("enter insert node value:");
                scanf("%d %s", &x,a);
                root = insertNode(root, x,a);
            

            break;
        case 2:
            printf("!---------------------------!\n");
            inorder(root);
            printf("\n!-------------------------!\n");
            break;
        
        case 3:
            printf("enter search value:");
            scanf("%d", &x);

            search(root, x);
            break;
        // case 6:
        //     printf("enter value to delete:");
        //     scanf("%d", &x);
        //     root = delete(root, x);
        //     break;
        // case 7:
        //     exit(0);
        }
    }

    return 0;
}
