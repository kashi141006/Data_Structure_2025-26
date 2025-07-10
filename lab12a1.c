#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *insertEnd(struct node *first, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
        return first;
    }
}
struct node *copyLink(struct node *first)
{
    if (first == NULL)
    {
        return NULL;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *pred = NULL;
    newNode->info = first->info;
    struct node *begin = newNode;

    struct node *save = first;
    while (save->link != NULL)
    {
        pred = newNode;
        save = save->link;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = save->info;
       
        pred->link = newNode;
    }
     newNode->link = NULL;
     return begin;
    
}

void display(struct node *save)
{

    if (save == NULL)
    {
        printf("empty");
        return;
    }
    while (save != NULL)
    {
        printf("%d->", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

void main()
{
    struct node *first = NULL;
    struct node *copy = NULL;
    int n, x, choice;
    while (1)
    {
        printf("1.first linked list\n");
        printf("2.disply first linked \n");
        printf("3.copy linked list\n");
        printf("4.Display copy\n");
        printf("5.Exit \n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter number of node:");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                printf("enter number of node value:");
                scanf("%d", &x);
                first = insertEnd(first, x);
            }
            break;
        case 2:

            display(first);
            break;
        case 3:
            copy = copyLink(first);
            printf("List copied successfully.\n");

            break;
        case 4:
            printf("---copied linked list----\n");
            display(copy);
            printf("----------------------------\n");
            break;
            case 5:
            exit(0);
        default:
            break;
        }
    }
}