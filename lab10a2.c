#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
// Insert At First
void insertAtFirst(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}
// Insert At Last
void insertAtEnd(int x)
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
}

// Insert at Ordered List
void insertAtOrd(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    if (first == NULL || x <= first->info)
    {

        newNode->link = first;
        first = newNode;
        return;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL && x >= save->link->info)
        {
            save = save->link;
        }
        newNode->link = save->link;
        save->link = newNode;
    }
}
// Delete First node
void deleteFirst()
{
    if (first == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    struct node *save = first;
    first = first->link;
    free(save);
}
// Delete last node
void deleteLast()
{
    if (first == NULL)
    {
        printf("linked list empty");
        return;
    }
    if (first->link == NULL)
    {
        free(first);
        first = NULL;
        printf("Linked List is Empty");
        return;
    }
    struct node *save = first;
    while (save->link->link != NULL)
    {
        save = save->link;
    }

    free(save->link);
    save->link = NULL;
}
// Delete Ordered node
void deleteOrd(int x)
{
    if (first == NULL)
    {
        printf("linked list empty");
        return;
    }
    struct node *save = first, *prev = NULL;
    if (first->info == x)
    {
        first = first->link;
        free(save);
        return;
    }
    while (save != NULL && save->info != x)
    {
        prev = save;
        save = save->link;
    }
    if (save == NULL)
    {
        printf("Node not found");
        return;
    }
    prev->link = save->link;
    free(save);
}
// count node
void countNode()
{
    int count = 0;

    struct node *save = first;
    while (save != NULL)
    {
        count++;
        save = save->link;
    }
printf("!-------------count------------------!\n");
    printf("count:%d\n", count);
    
printf("!------------------------------------!\n");
}
void display()
{
    struct node *save = first;
    if (save == NULL)
    {
        printf("link is empty");
        return;
    }

    printf("!--------------Linked List:-----------------!\n");

    while (save != NULL)
    {
        printf("%d->", save->info);
        save = save->link;
    }
    printf("NULL\n");
    printf("!-------------------------------------------!\n");
}
int main()
{
    int x;
    int choice;
    while (1)
    {
        printf("1.Insert at First\n");
        printf("2.Insert at Last\n");
        printf("3.Insert at Orderd List\n");
        printf("4.Delete First node\n");
        printf("5.Delete Last node\n");
        printf("6.Delete Ordered list node\n");
        printf("7.display\n");
        printf("8.count\n");
        printf("9.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter first node value:");
            scanf("%d", &x);
            insertAtFirst(x);
            break;
        case 2:
            printf("enter node last value:");
            scanf("%d", &x);
            insertAtEnd(x);
            break;
        case 3:
            printf("enter node ordered value:");
            scanf("%d", &x);
            insertAtOrd(x);
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            printf("delete ordered list from above linked list value:");
            scanf("%d", &x);
            deleteOrd(x);
            break;
        case 7:
            display();
            break;
        case 8:
            countNode();
            break;
        case 9:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}