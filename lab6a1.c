#include <stdio.h>
#include <stdlib.h>
int n = 5;
int s[100];
int top = -1;
void push(int x)
{
    if (top > 5)
    {
        printf("stack overflow\n");
    }
    top++;
    s[top] = x;
}
void pop()
{
    if (top == -1)
    {
        printf("underflow\n");
    }
    top--;
    s[top + 1];
}
int peep(int i)
{
    if (top - i + 1 < 0)
    {
        printf("underflow\n");
    }
    return s[top - i];
}
void change(int i, int x)
{
    if (top - i + 1 < 0)
    {
        printf("underflow\n");
    }
     s[top - i] = x;
}
void display()
{
    if (top <= 0)
    {
        printf("invalid\n");
    }
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}
void main()
{
    int choice, n, x, a, i;
    while (1)
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.change\n");
        printf("5.display\n");
        printf("6.exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter size:");
            scanf("%d", &n);
            for (int j = 0; j < n; j++)
            {
                printf("Enter push value:");
                scanf("%d", &x);
                push(x);
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter index value:");
            scanf("%d", &x);
            a = peep(x);
            printf("%d\n", a);

            break;
        case 4:
            printf("Enter new value:");
            scanf("%d",&x);
            printf("enter index:");
            scanf("%d",&i);
            change(i, x);
            break;
        case 5:
            printf("!-------display--------!\n");
            display();
            printf("!----------------------!\n");
            break;

        case 6:
            exit(0);
        }
    }
}