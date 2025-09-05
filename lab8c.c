#include <stdio.h>
#include <stdlib.h>
int front = -1;
int rear = -1;
int n = 5;
int a[20];

void dqInsert_rear(int y)
{
    if (rear >= n - 1)
    {
        printf("Queqe Overfloe\n");
    }
    rear++;
    a[rear] = y;
    if (front == -1)
    {
        front = 0;
    }
}
void dqInsert_Front(int y)
{
    if (front == 0)
    {
        printf("overflow\n");
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        front--;
    }
    a[front] = y;
}
int dqDelete_Front()
{
    int y;
    if (front == -1)
    {
        printf("underflow\n");
        return 0;
    }
    y = a[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return y;
}

int dqDelete_Rear()
{ int y;
    if (rear == -1)
    {
        printf("underflow\n");
        return 0;
    }
    y = a[rear];
    if (front == rear)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        rear--;
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
        printf("1.enter enqueqe\n");
        printf("2.dequeqe elment\n");
        printf("3.enter double endend  enqueqe\n");
        printf("4.double enddeddequeqe elment\n");
        printf("5.dispaly\n");
        printf("6.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
                printf("enter element:");
                scanf("%d", &x);
                dqInsert_rear(x);
           
            break;

        case 2:
            dqDelete_Front();
            break;
        case 3:
             
                printf("enter element:");
                scanf("%d", &x);
                dqInsert_Front(x);
           
            break;
        case 4:
            dqDelete_Rear();
            break;
        case 5:
            display();
            break;
            case 6:
            exit(0);
        }
    }
}