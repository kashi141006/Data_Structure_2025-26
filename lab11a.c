#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *push(struct node *first, int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->link = first;
    return newnode;
}
struct node *pop(struct node *first)
{
    if (first == NULL)
    {
        printf("empty\n");
        return NULL;
    }
    struct node *save = first;
    printf("%d\n", first->info);
    first = first->link;
    free(save);
    return first;
}
struct node *peep(struct node *first, int pos)
{
    int count = 0;
    while (first != NULL && count < pos)
    {
        first = first->link;
        count++;
    }
    if (first == NULL && pos <= 0)
    {
        printf("invalid\n");
    }
    else
    {
        printf(" Element atposition %d  from top:%d", pos, first->info);
    }
    return first;
}
struct node *change(struct node *first, int pos, int x)
{
    int count = 0;
    struct node *save = first;
    while (save != NULL && count < pos)
    {
        save = save->link;
            count++;  

    }
    if (save == NULL && pos <= 0)
    {
        printf("Invalis Position\n");
    }
    else
    {
        printf("value at position %d changed from %d to %d \n",pos,save->info,x);
        save->info=x;
    }
    return first;
}
void display(struct node *first)
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
        printf("|%d|\n", save->info);
        save = save->link;
    }

    printf("!-------------------------------------------!\n");
}
void main()
{
    struct node *first = NULL;
    int x, n, choice, pos;
    while (1)
    {
        printf("\n----- STACK MENU -----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. PEEP\n");
        printf("5. CHANGE\n");
        printf("6. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter node :");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter push:");
                scanf("%d", &x);
                first = push(first, x);
            }
            break;
        case 2:

            first = pop(first);
            printf("removed successfully\n");
            break;

        case 3:
            display(first);

            break;
        case 4:
            printf("Enter position for peep:");
            scanf("%d", &pos);
            first = peep(first, pos);
            break;
            case 5:
            printf("Enter position to insert new value:");
            scanf("%d",&pos);
            printf("enter new value:");
            scanf("%d",&x);
            first=change(first,pos,x);
            break;
            case 6:
            exit(0);
        }
    }
}
