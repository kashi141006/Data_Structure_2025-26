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
int countNode(struct node *first)
{
    int count = 0;
    while (first != NULL)
    {
        first = first->link;
        count++;
    }
    return count;
}
struct node *swapNode(struct node *first, int k)
{
    int n = countNode(first);
    if (k > n)
    {
        printf("invalid \n");
    }
    if (2 * k - 1 == n)
    {
        printf("No need to swap number\n");
        return first;
    }
    struct node *save = first;
    for (int i = 1; i < k; i++)
    {
        save = save->link;
    }
    struct node *temp = first;
    for (int i = 1; i <n-k+1; i++)
    {
        temp = temp->link;
    }
    int t = save->info;
    save->info = temp->info;
    temp->info = t;
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
    struct node *swap = NULL;

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
            printf("Enter value of K: ");
            scanf("%d", &k);
            first = swapNode(first, k);
            printf("swap node successfully\n");
            break;
        case 4:
            exit(0);
             
        }
    }
}
