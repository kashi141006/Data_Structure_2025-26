#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
};
int n = 5;
struct node pq[5];
int front = -1;
int rear = -1;
void priEnqueqe(int y, int x)
{
    if (rear >= n - 1)
    {
        printf("overflow\n");
    }
    rear++;
    pq[rear].data = x;
    pq[rear].priority = y;
    if (front == -1)
    {
        front = 0;
    }
}
void priDequue()
{
    if (front == -1)
    {
        printf("underflow\n");
    }
    if (front == rear)
    {
        printf("deleted {%d %d\n}", pq[front].data, pq[front].priority);
        front = -1;
        rear = -1;
    }
    int max_pri = front;
    for (int i = front + 1; i <=rear; i++)
    {
        if (pq[i].priority > pq[max_pri].priority)
        {
            max_pri = i;
        }
    }
    printf("deleted element:{%d %d\n }",pq[max_pri].data,pq[max_pri].priority);

    for (int i = max_pri ; i <= rear; i++)
    {
        pq[i] = pq[i + 1];
    }
    rear--;
}
void display()
{
    if (front == -1 || rear == -1)
    {
        printf("empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",pq[i]);
    }
    printf("\n");
}
void main()
{
    int choice;
    int x;
    int y;
    while (1)
    {
        printf("1. enter enqueqe\n");
        printf("2.dequeqe elment\n");
        printf("3.dispaly\n");
        printf("4.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("enter element data and priority:");
            scanf("%d %d", &x, &y);
            priEnqueqe(y, x);

            break;
        case 2:
            priDequue();
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}