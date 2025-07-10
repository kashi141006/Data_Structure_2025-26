#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *douInsertFirst(struct node *first, int x)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->lptr = NULL;
    newnode->rptr = first;
    if (first != NULL)
    {
        first->lptr = newnode;
        first = newnode;
    }
}
struct node *douInsertLast(struct node *first, int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = x;
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    if (first == NULL)
    {
        first = newnode;
        return first;
    }
    struct node *save = first;
    while (save->rptr != NULL)
    {
        save = save->rptr;
    }
    save->rptr = newnode;
    newnode->lptr = save;
    return first;
}
struct node *douDelete(struct node *first, int pos)
{
    if (first == NULL)
    {
        printf("empty\n");
    }
    struct node *save = first;
    for (int i = 0; i < pos && save != NULL; i++)
    { 
        save=save->rptr;
    }
    if(save==NULL){
        printf("Invalid position\n");
        
    }
    if(save->lptr!=NULL)
    {
        save->lptr->rptr=save->rptr;

    }else{
    first=save->rptr;
    }
    if(save->rptr!=NULL){
        save->rptr->lptr=save->lptr;
    }
    free(save);
    return first;
}
void display(struct node *first)

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
    struct node *first = NULL;
    int n, x, pos,choice;
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
            printf("enter number of node:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter first node value:");
                scanf("%d", &x);
                first = douInsertFirst(first, x);
            }
            break;
        case 2:
            printf("enter number of node:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("enter first node value:");
                scanf("%d", &x);
                first = douInsertLast(first, x);
            }
            break;
        // case 3:
        //     printf("enter node ordered value:");
        //     scanf("%d", &x);
        //     insertAtOrd(x);
        //     break;
        case 4:
        printf("enter position:");
        scanf("%d",&pos);
            first=douDelete(first,pos);
            break;
        // case 5:
        //     deleteLast();
        //     break;
        // case 6:
        //     printf("delete ordered list from above linked list value:");
        //     scanf("%d", &x);
        //     deleteOrd(x);
        //     break;
        case 7:
            display(first);
            break;
        // case 8:
        //     countNode();
        //     break;
        case 9:
            exit(0);

        default:
            break;
        }
    }
}
