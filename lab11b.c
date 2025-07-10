#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *enqueue(struct node *first, struct node **rear, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Linked list empty\n");
        return NULL;
    }
    newNode->info = x;
    newNode->link = NULL;
    if (*rear == NULL)
    {
        first = *rear = newNode;
    }
    else
    {
        (*rear)->link = newNode;
        *rear = newNode;
    }
    return first;
}
struct node *dequeue(struct node *first)
{
    if (first == NULL)
    {
        printf("Linked is empty\n");
        return NULL;
    }
    struct node *save = first;
    first = first->link;
    free(save);
    return first;
}
void display(struct node *first)
{
    struct node *save = first;
    if (save == NULL)
    {
        printf("link is empty\n");
    }
    while (save != NULL)
    {
        printf("%d\n", save->info);
        save = save->link;
    }
}
void main()
{
    struct node *first = NULL;
    struct node *rear = NULL;
    int x, n, choice;
    while (1)
    {
        printf("1.Enqueqe\n");
        printf("2.Dequeqe\n ");
        printf("3.Display\n");
        printf("4.exit\n");
        printf("Eneter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter insert value:");
            scanf("%d", &x);
            first = enqueue(first, &rear, x);
            break;
        case 2:
            first = dequeue(first);
            printf("Dequeue successfully\n");
            break;
        case 3:
            display(first);

            break;
        case 4:
            exit(0);
        }
    }
}