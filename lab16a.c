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
    if (root->info < value)
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
    printf("%d", root->info);
    inorder(root->rptr);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d", root->info);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d", root->info);
    preorder(root->lptr);
    preorder(root->rptr);
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
struct node *minimumNode(struct node *root)
{
    struct node *temp = root->rptr;
    while (root->lptr != NULL)
    {
        temp = temp->lptr;
    }
    return root;
}
struct node *delete(struct node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (value < root->info)
    {
        root->lptr = delete(root->lptr, value);
    }
    else if (value > root->info)
    {
        root->rptr = delete(root->rptr, value);
    }
    else
    {
        if (root->lptr == NULL)
        {
            struct node *temp = root->rptr;
            free(root);
            return temp;
        }
        else if (root->rptr == NULL)
        {
            struct node *temp = root->lptr;
            free(root);
            return temp;
        }
        else
        {
            struct node *save = minimumNode(root->rptr);
            root->info = save->info;
            root->rptr = delete(root->rptr, save->info);
        }
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int n, x, choice;

    while (1)
    {
        printf("1.Insert node\n");
        printf("2.inorder traversel\n");
        printf("3.post order traversel\n");
        printf("4.pre order traversel\n");
        printf("5.search\n");
        printf("6.delete\n");
        printf("7.exit\n");
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
                root = insertNode(root, x);
            }

            break;
        case 2:
            printf("!---------------------------!\n");
            inorder(root);
            printf("\n!-------------------------!\n");
            break;
        case 3:
            printf("!---------------------------!\n");
            postorder(root);
            printf("\n!-------------------------!\n");
            break;
        case 4:
            printf("!---------------------------!\n");
            preorder(root);
            printf("\n!-------------------------!\n");
            break;
        case 5:
            printf("enter search value:");
            scanf("%d", &x);

            search(root, x);
            break;
        case 6:
            printf("enter value to delete:");
            scanf("%d", &x);
            root = delete(root, x);
            break;
        case 7:
            exit(0);
        }
    }

    return 0;
}