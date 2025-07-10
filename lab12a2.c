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
    }
    return first;
}
struct node *reverseLink(struct node *first)
{
    struct node *current = first, *pred = NULL, *next = NULL;
    if (first == NULL)
    {
        printf("empty");
    }
    while (current != NULL)
    {
        next = current->link;
        current->link = pred;
        pred = current;
        current = next;
    }
    return pred;
}
void display(struct node *first)
{
    struct node *save = first;
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
int main()
{
    struct node *first = NULL;
    struct node *reverse = NULL;
    int n, x, choice;
    while (1)
    {
        printf("1.first linked list\n");
        printf("2.disply first linked \n");
        printf("3.Reverse  linked list\n");
        printf("4.Display reverse linked list\n");
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
            reverse = reverseLink(first);
            printf("linked reverse successfully\n");
            break;
        case 4:
            printf("--- Reverse linked list----\n");
            display(reverse);
            printf("----------------------------\n");
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
}