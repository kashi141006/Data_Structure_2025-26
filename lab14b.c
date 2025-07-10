#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *last = NULL;
struct node *cirInsertEnd(struct node *first, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first == NULL)
    {
        newNode->link = newNode;
        first = newNode;
        last = newNode;
    }
    else
    {
        newNode->link = first;
        last->link = newNode;
        last = newNode;
    }
    return first;
}
int countNode(struct node *first)
{
    int count = 1;
    struct node *save = first;
    while (save->link != first)
    {
        count++;
        save = save->link;
    }
    first = first->link;

    return count;
}
void display(struct node *first)
{
    if (first == NULL)
    {
        printf("empty\n");
    }
    struct node *save=first;
     while (1)
     {
         printf("|%d|->",save->info);
         save=save->link;
         if(first==save){
            break;
         }
     }
     printf("\n");
     
}

struct node *splitNode(struct node *first)
{
    int n = countNode(first);
    int count = 0;
    struct node *p = first;
    struct node *q = first; 
    
        while (p->link != first && p->link->link != first)
        {
            q = q->link;
            p = p->link->link;
        }
        if (p->link->link == first)
        {
            p = p->link;
        }
        struct node *head = first;
        struct node *second = q->link;

        q->link = head;
        p->link = second;
        printf("!-----First split node----!\n");
        display(head);
        printf("!-----------second spilt node-----!\n");
        display(second);
    
}
void main()
{
    struct node *first = NULL;
    int x, n, choice;
    while (1)
    {
        printf("1.insert node\n");
        printf("2.Display\n");
        printf("3.count node\n");
        printf("4.exit\n");
        printf("5.spit method call\n");
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

                first = cirInsertEnd(first, x);
            }
            break;
        case 2:
            display(first);
            break;
        case 3:
            printf("count node:%d\n", countNode(first));
            break;
        case 4:
            exit(0);
            break;
        case 5:
            splitNode(first);
            printf("split node successfully\n");
        }
    }
}
