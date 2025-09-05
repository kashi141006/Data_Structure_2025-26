#include <stdio.h>
#include <stdlib.h>
#define n 10
int hashSet[10];
void intial()
{

    for (int i = 0; i < n; i++)
    {
        hashSet[i] = -1;
    }
}
int indexfun(int key)
{
    return key % n;
}
void add(int key)
{
    int index = indexfun(key);
    if (hashSet[index] == -1)
    {
        hashSet[index] = key;
        return;
    }
    else if (hashSet[index] == key)
    {
        printf("not exits\n");
        return;
    }
    else
    {
        for (int probe = 1; probe < n; probe++)
        {
            int i = ((index + probe) % n);
            if (hashSet[i] == -1)
            {
                hashSet[i] = key;
                return;
            }
            else if (hashSet[i] == key)
            {
                printf("key exits\n");
                return;
            }
        }
        printf("hash set is full\n");
    }
}
void display()
{   
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", hashSet[i]);
    }
}
void main()
{
    int choice;
    int x;
    intial();
    while (1)
    {
        printf("\n1.insert elemnet\n");
        printf("2.display\n");
        printf("3.exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter element:");
            scanf("%d", &x);
           add(x);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        }
    }
}