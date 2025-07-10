#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *cirInsertFirst(struct node *first, struct node **last, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first == NULL)
    {
        newNode->link = newNode;
        *last = newNode;
        first = newNode;
    }
    else
    {
        newNode->link = first;
        (*last)->link = newNode;
        first = newNode;
    }
    return first;
}
struct node *cirInsertLast(struct node *first, struct node **last, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first == NULL)
    {
        newNode->link = newNode;
        *last = newNode;
        first = newNode;
    }
    else
    {
        newNode->link = first;
        (*last)->link = newNode;
        *last = newNode;
    }
    return first;
}
// ordered linked list node
struct node *cirInsertOrd(struct node *first, struct node **last, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first == NULL)
    {
        newNode->link = newNode;
        first = newNode;
        *last = newNode;
        return first;
    }
    if (newNode->info <= first->info)
    {
        newNode->link = first;
        (*last)->link = newNode;
        first = newNode;
        return first;
    }
    struct node *save = first;
    while (save != *last && newNode->info >= save->link->info)
    {
        save = save->link;
    }
    newNode->link = save->link;
    save->link = newNode;
    if (save == *last)
    {
        *last = newNode;
    }
    return first;
}
// Delete node
struct node *cirDeleteNode(struct node *first, struct node **last, int pos)
{
    if (first == NULL)
    {
        printf("Linked  list is empty");
        return NULL;
    }
    struct node *save = first, *pred = *last;
    int count = 0;
    if (first == *last && pos == 0)
    {
        free(first);
        *last = NULL;
        return NULL;
    }
    while (save != *last && count != pos)
    {
        pred = save;
        save = save->link;
        count++;
    }
    if (count == pos)
    {
        if (save == first)
        {
            first = first->link;
            (*last)->link = first;
        }
        else
        {
            pred->link = save->link;
            if (save == *last)
            {
                *last = pred;
            }
        }
        free(save);
    }
    return first;
}
int  countNode(struct node *last)
{
    if (last == NULL)
    {
        return 0;
    }
    int count = 0;
    struct node *save = last->link;
    while (save != last)
    {
        count++;
        save = save->link;
    }
    count++; //include last node
    return count;
}
void display(struct node *last)
{
    if (last == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    struct node *save = last->link;
    do
    {
        printf("%d->", save->info);
        save = save->link;

    } while (save != last->link);
    printf("circular\n"); // using while loop printf last in last->info instead of null
}

void main()
{
    int n, pos, x, choice;
    struct node *first = NULL;
    struct node *last = NULL;
    while (1)
    {
        printf("1.Insert at First\n");
        printf("2.Insert at last\n");
        printf("3.Insert at Orderd List\n");
        printf("4.Delete  node\n");
        printf("5.Count node\n");
        printf("6.display\n");
      
        printf("7.exit\n");
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
                first = cirInsertFirst(first, &last, x);
            }
            break;
        case 2:
            printf("enter number of node:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter number of node value:");
                scanf("%d", &x);

                first = cirInsertLast(first, &last, x);
            }
            break;
        case 3:
            printf("Enter number of node ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter number of node value:");
                scanf("%d", &x);
                first = cirInsertOrd(first, &last, x);
            }
            break;
        case 4:
            printf("enter delete node position:");
            scanf("%d", &pos);
            first = cirDeleteNode(first, &last, pos);
            printf("delete successfully\n");
            break;

        case 5:
             printf("count:%d\n",countNode(last));
            break;
        case 6:
            printf("!---------linked list---------------!\n");
            printf("Linked List: ");
            display(last);
            printf("!-----------------------------------!\n");
            break;
            
        case 7:
            exit(0);
        }
    }
}
