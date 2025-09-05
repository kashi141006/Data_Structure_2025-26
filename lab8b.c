#include <stdio.h>
#include <stdlib.h>
int front = -1;
int rear = -1;
int n = 5;
int a[20];

void cirnEqueue(int y)
{
    if (rear == n - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    if (front == rear)
    {
        printf("overflow\n");
        return;
    }

    a[rear] = y;
    if (front == -1)
    {
        front = 0;
    }
}
int cirDequeqe()
{
    int y;
    if (front == -1)
    {
        printf("underflow\n");
         
    }
    y = a[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
        return y;
    }

    if (front == n-1)
    {
        front = 0;
       
    }
    else
    {
        front++;
    }
    return y;
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

        printf("%d ", a[i]);
    }
    printf("\n");
}
void main()
{
    int choice;
    int x;
    int k;
    while (1)
    {
        printf("1. enter enqueqe\n");
        printf("2.enqueqe\n");
        printf("3.dequeqe elment\n");
        printf("4.dequeqe\n");
        printf("5.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("enter element:");
                scanf("%d", &x);
                cirnEqueue(x);
            }
            break;
        case 2:
            display();
            break;

        case 3:
            cirDequeqe();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        }
    }
}