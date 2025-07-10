#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

void insertEnd(struct node **first, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (*first == NULL)
    {
        *first = newNode;
    }
    else
    {
        struct node *save = *first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }
}
void addList(struct node *ptr1, struct node *ptr2, struct node **result)
{

    int carry = 0;
    while (ptr1 != NULL || ptr2 != NULL || carry)
    {
        int sum = carry;
        if (ptr1 != NULL)
        {
            sum += ptr1->info;
            ptr1 = ptr1->link;
        }
        if (ptr2 != NULL)
        {
            sum += ptr2->info;
            ptr2 = ptr2->link;
        }
        carry = sum / 10;
        insertEnd(result, sum % 10);
    }
}

 
void subtractLinked(struct node *ptr1, struct node *ptr2, struct node **result)
{
     
    while (ptr1 != NULL)
    {
        int sub = ptr1->info - borrow- (ptr2 ? ptr2->info : 0);
        if (ptr2 != NULL)
        {
            sub -= ptr2->info;
            ptr2 = ptr2->link;
        }
        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        insertEnd(result, sub);
        ptr1 = ptr1->link;
    }
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
    int n, choice, x;
    struct node *ptr1 = NULL, *ptr2 = NULL, *sumList = NULL, *subList = NULL;
    while (1)
    {
        printf("1.Addition of two Linked List\n");
        printf("2.Substraction of two Linked List\n");
        printf("3.Display first Linked List\n");
        printf("4.Display second Linked List\n");
        printf("5.Sumlist\n");
        printf("6.Sublist\n");
        printf("7.Exit\n");

        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("enter number of node:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter node value:");
                scanf("%d", &x);
                insertEnd(&ptr1, x);
            }
            break;
        case 2:

            printf("enter number of node:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter node value:");
                scanf("%d", &x);
                insertEnd(&ptr2, x);
            }
            break;
        case 3:
            printf("!-------First Linked List---------!\n");
            display(ptr1);
            break;
        case 4:
            printf("!-------Second Linked List---------!\n");
            display(ptr2);
            break;
        case 5:
            addList(ptr1, ptr2, &sumList);
            printf("!----------Sum List---------------!\n");
            display(sumList);
            break;
        case 6:
            subtractLinked(ptr1, ptr2, &subList);
            printf("!----------SubList---------------!\n");
            display(subList);
            break;
        case 7:
            exit(0);
        default:
            break;
        }
    }
}