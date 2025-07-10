#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

// Insert At Last
struct node *insertAtEnd(struct node *first, int x)
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
int digitSquareSum(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int happyNumber(int n) {
    int slow = n, fast = n;

    do {
        slow = digitSquareSum(slow);           // move 1 step
        fast = digitSquareSum(digitSquareSum(fast)); // move 2 steps
    } while (slow != fast);

    return (slow == 1);
}

struct node *happyNumberNode(struct node *first)
{
    struct node *save = first;
    while (save != NULL)
    {
        int a = happyNumber(save->info);

        struct node *happyNode = (struct node *)malloc(sizeof(struct node));
        happyNode->info = a;
        happyNode->link = save->link;
        save->link = happyNode;
        save = happyNode->link;
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
        printf("%d->", save->info);
        save = save->link;
    }
    printf("NULL\n");
    printf("!-------------------------------------------!\n");
}
void main()
{
    struct node *first = NULL, *happy = NULL;
    int n, x, choice;
    while (1)
    {
        printf("1.insert node\n");
        printf("2.display first node\n");
        printf("3. insert happy number\n");
        printf("4.display happy number\n");
        printf("5.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter value %d: ", i + 1);
                scanf("%d", &x);
                first = insertAtEnd(first, x);
            }

            break;
        case 2:
            display(first);
            break;
        case 3:
            first = happyNumberNode(first);
            printf("Happy number successfully\n");
            break;
        case 4:
            display(first);
            break;
        case 5:
            exit(0);
        }
    }
}