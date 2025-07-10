#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *first;

struct node *last;
void douinertlast(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;

    if (first == NULL)
    {
        newNode->lptr = NULL;
        newNode->rptr = NULL;
        first = newNode;
        last = newNode;
    }
    else
    {
        newNode->rptr = NULL;
        newNode->lptr = last;
        last->rptr = newNode;
        last = newNode;
    }
}

void deleteAlternate()
{
    struct node *save = first, *temp;

    while (save != NULL && save->rptr != NULL)
    {
        temp = save->rptr;
        save->rptr = temp->rptr;
        temp->rptr->lptr = save;
        save = save->rptr;
        free(temp);
    }
}
void display()

{
    struct node *save = first;
    if (save == NULL)
    {
        printf("empty\n");
        return;
    }
    while (save != NULL)
    {
        printf("%d<->", save->info);
        save = save->rptr;
    }
    printf("NULL\n");
}
void main()
{
    int x, n, choice;
    while (1)
    {
        printf("1.insert node\n");
        printf("2.Display\n");
        printf("3.exit\n");
        printf("4.delete call\n");
        printf("enter choice:");
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

                douinertlast(x);
            }
            break;
        case 2:
            display();
            break;

        case 3:
            exit(0);
            break;
        case 4:
            deleteAlternate();
            break;
        }
    }
}