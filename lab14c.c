#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *link;
};
struct node *last = NULL;

struct node *cirInsertEnd(struct node *first, int coeff, int pow)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->pow = pow;

    if (first == NULL)
    
    {
        newNode->link = newNode;
        last = newNode;
        return newNode;
    }
    else
    {
        newNode->link = first;
        last->link = newNode;
        last = newNode;
    }
    return first;
}
void display(struct node *first)
{
    if (first == NULL)
    {
        printf("Empty polynomial\n");
        return;
    }

    struct node *save = first->link;
    do
    {
        printf("%dx^%d", save->coeff, save->pow);
        save = save->link;
        if (save != first->link)
            printf(" + ");
    } while (save != first->link);
    printf("\n");
}
struct node *addNode(struct node *p1, struct node *p2)
{
    if (p1 == NULL)
    {
        return p2;
    }
    if (p2 == NULL)
    {
        return p1;
    }
    struct node *t1 = p1->link;
    struct node *t2 = p2->link;
    struct node *result = NULL;
    do
    {
        if (t1->pow == t2->pow)
        {
            result = cirInsertEnd(result, t1->coeff + t2->coeff, t1->pow);
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->pow > t2->pow)
        {
            result = cirInsertEnd(result, t1->coeff, t1->pow);
            t1 = t1->link;
        }
        else
        {
            result = cirInsertEnd(result, t2->coeff, t2->pow);
            t2 = t2->link;
        }
    } while (t1 != p1->link && t2 != p2->link);

    while (t1 != p1->link)
    {
        result = cirInsertEnd(result, t1->coeff, t1->pow);
        t1 = t1->link;
    }
    while (t2 != p2->link)
    {
        result = cirInsertEnd(result, t2->coeff, t2->pow);
        t2 = t2->link;
    }
    display(p1);
    display(p2);
}
int main()
{
    int n, coeff, pow, choice;
    struct node *sum = NULL;
    struct node *first = NULL;

    struct node *poly1 = NULL;
    struct node *poly2 = NULL;
    while (1)
    {
        printf("1.Enter first polinomial\n");
        printf("2.Enter second polinomial\n");
        printf("3.Add polynomial\n");
        printf("4.Display poly 1\n");
        printf("5.Display poly 2\n");
        printf("6.display sum node\n");
        printf("7.exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter first polinomial node:");
            scanf("%d", &n);
            // poly1=NULL;
            for (int i = 0; i < n; i++)
            {
                printf("Enter coeff and power:");
                scanf("%d %d", &coeff, &pow);
                poly1 = cirInsertEnd(poly1, coeff, pow);
            }

            break;
        case 2:
            printf("enter second polinomial node:");
            scanf("%d", &n);
            // poly2=NULL;
            for (int i = 0; i < n; i++)
            {
                printf("Enter coeff and power:");
                scanf("%d %d", &coeff, &pow);
                poly2 = cirInsertEnd(poly2, coeff, pow);
            }
            break;
        case 3:
            sum = addNode(poly1, poly2);
            printf("Add polynomial success fully\n");
            break;
        case 4:
            printf("First polynomil\n");
            display(poly1);
            break;

        case 5:
            printf("Second polynomial\n");
            display(poly2);
            break;
        case 6:
            printf("Sum polynomial\n");
            display(sum);
            break;
        case 7:
            exit(0);
        }
    }

    return 0;
}