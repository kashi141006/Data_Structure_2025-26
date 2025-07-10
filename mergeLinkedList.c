#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;
struct node *merged = NULL;

void insertAtOrd1(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first1 == NULL || x <= first1->info)
    {

        newNode->link = first1;
        first1 = newNode;
        return;
    }
    else
    {
        struct node *save = first1;
        while (save->link != NULL && x >= save->link->info)
        {
            save = save->link;
        }
        newNode->link = save->link;
        save->link = newNode;
    }
}
void insertAtOrd2(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first2 == NULL || x <= first2->info)
    {

        newNode->link = first2;
        first2 = newNode;
        return;
    }
    else
    {
        struct node *save = first2;
        while (save->link != NULL && x >= save->link->info)
        {
            save = save->link;
        }
        newNode->link = save->link;
        save->link = newNode;
    }
}
void mergedList()
{
    struct node *ptr1 = first1, *ptr2 = first2;
    struct node *last = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (ptr1->info <= ptr2->info)
        {
            newNode->info = ptr1->info;
            ptr1 = ptr1->link;
        }
        else
        {
            newNode->info = ptr2->info;
            ptr2 = ptr2->link;
        }
        newNode->link = NULL;
        if (merged == NULL)
        {
            merged = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
    }
    while (ptr1 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = ptr1->info;
        newNode->link = NULL;
        last->link = newNode;
        last = newNode;
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = ptr2->info;
        newNode->link = NULL;
        last->link = newNode;
        last = newNode;
        ptr2 = ptr2->link;
    }
}

void display(struct node *save)
{

    if (save == NULL)
    {
        printf("empty");
        return;
    }
    while (save!= NULL)
    {
        printf("%d->", save->info);
        save= save->link;
    }
    printf("NULL\n");
}

int main()
{
    int n, x1, x2;
    printf("Enter node:");
    scanf("%d", &n);
    printf("--------------first LInked list----------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter node value:");
        scanf("%d", &x1);
        insertAtOrd1(x1);
    }
    printf("--------------Second LInked list----------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter node value:");
        scanf("%d", &x2);
        insertAtOrd2(x2);
    }
    printf("First Node inserted\n");
    display(first1);
    printf("Second Node inserted\n");

    display(first2);

    mergedList();
    printf("Merged Linked List\n");
    display(merged);
    return 0;
}