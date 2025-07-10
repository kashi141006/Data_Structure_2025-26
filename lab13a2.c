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
int findGcd(int a, int b)
{
    return b==0?a:findGcd(b,a%b);
}
struct node *gcdNodelink(struct node *first)
{   
    struct node *current = first;

    while (current != NULL&& current->link!=NULL)
    {
         
        int a = current->info;
        int b = current->link->info;
        int gcd = findGcd(a, b);
        struct node *gcdNode = (struct node *)malloc(sizeof(struct node));
        gcdNode->info = gcd;
        gcdNode->link = current->link;
        current->link=gcdNode;
        current=gcdNode->link;

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
    struct node *gcdi = NULL;
    int n, x, choice;
    while (1)
    {
        printf("1.first linked list\n");
        printf("2.disply first linked \n");
        printf("3.gcd linked list\n");
        printf("4. display gcd linked list\n");
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
            gcdi= gcdNodelink(first);
            printf("successfully\n");
            break;
        case 4:
            display(gcdi);
            break;
        case 5:
            exit(0);
        }
    }
}