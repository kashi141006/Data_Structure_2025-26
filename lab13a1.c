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
struct node *sortNode(struct node *first)
{
    struct node *i, *j;
    int temp;
    for (i = first; i->link != NULL; i = i->link)
    {
        for (j =i->link; j->link != NULL; j = j->link)
        {
            if (i->info > j->info)
            {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
    return first;
    
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
    struct node *sort = NULL;
    int n, x, choice;
    while (1)
    {
        printf("1.first linked list\n");
        printf("2.disply first linked \n");

        printf("3.sort linked list\n");
        printf("4. display sort linked list\n");
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
            sort = sortNode(first);
            printf("sort successfully\n");
            break;
        case 4:
            display(sort);
            break;
        case 5:
            exit(0);
        }
    }
}