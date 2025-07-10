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

struct node *swapnode(struct node *first)
{
    struct node *p = first;
    struct node *q = first->link;
    struct node *temp = NULL;
    if (first == NULL || first->link == NULL)
    {
        return first;
    }

    first = q;
    while (1)
    {
        temp = q->link;
        q->link=p;
        if(temp==NULL || temp->link==NULL){
            p->link=temp;
            break;
        }
        p->link=temp->link;
        p=temp;
        q=p->link;
    }

    return first;
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
void main()
{
    struct node *first = NULL;

    int n, x, k, choice;
    while (1)
    {
        printf("1.first linked list\n");
        printf("2.disply first linked \n");
        printf("3.swap value of k posotion linked list\n");
        printf("4.Exit \n");
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

            first = swapnode(first);
            printf("swap node successfully\n");
            break;
        case 4:
            exit(0);
        }
    }
}
