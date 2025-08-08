#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

struct node *insertNode(struct node *root, int value)
{

    if (root == NULL)
    {
        root = createNode(value);
    }
    if (root->info > value)
    {
        root->lptr = insertNode(root->lptr, value);
    }
    else if (root->info < value)
    {
        root->rptr = insertNode(root->rptr, value);
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
    printf("%d ", root->info);
    inorder(root->rptr);
}
int compare(struct node *temp1, struct node *temp2)
{
    if (temp1 == NULL || temp2 == NULL)
    {
        return 0;
    }
    if (temp1->info != temp2->info)
    {
        printf("not same\n");
        return 1;
    }
    else
    {
        if (temp1->info == temp2->info)
        {
              compare(temp1->lptr, temp2->lptr);
              compare(temp1->rptr, temp2->rptr);
        }
    }

    // if(temp1==NULL && temp2==NULL){
    //     return 1;
    // }

    // return temp1->info==temp2->info && compare(temp1->rptr, temp2->rptr) && compare(temp1->lptr, temp2->lptr);
}

int main()
{
    struct node *temp1 = NULL;
    struct node *temp2 = NULL;
    int n, x, a, choice;

    while (1)
    {
        printf("1.Insert node for tree 1\n");
        printf("2.Insert node for tree 2\n");
        printf("3.inorder traversel for tree 1\n");
        printf("4.inorder traversel for tree 2\n");

        printf("5.compare\n");
        printf("6.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("enter number node :");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter insert node value:");
                scanf("%d", &x);
                temp1 = insertNode(temp1, x);
            }

            break;
        case 2:

            printf("enter number node :");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter insert node value:");
                scanf("%d", &x);
                temp2 = insertNode(temp2, x);
            }

            break;

        case 3:
            printf("!---------------------------!\n");
            inorder(temp1);
            printf("\n!-------------------------!\n");
            break;

        case 4:
            printf("!---------------------------!\n");
            inorder(temp2);
            printf("\n!-------------------------!\n");
            break;
        case 5:
            a = compare(temp1, temp2);
            if(a==0){
                printf("same\n");
            }
            break;
        case 6:
            exit(0);
            break;
        }
    }
    return 0;
}