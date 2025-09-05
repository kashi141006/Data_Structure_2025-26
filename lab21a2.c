
#include <stdio.h>
#include <stdlib.h>

int binarySearchItarative(int a[], int key, int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int middle = ((left + right) / 2);
        if (a[middle] == key)
            return middle;
        else if (key < a[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
}
int binarySearchRecursive(int a[], int left, int right, int key, int size)
{
    
    if (left <= right)
    {
        int middle = ((left + right) / 2);
        if (a[middle] == key)
            return middle;
        else if (key < a[middle])
            return binarySearchRecursive(a, left, middle - 1, key,size);
        else
            return binarySearchRecursive(a, middle + 1, right, key,size);
    }
    return -1;
}
void main()
{
    int n, value;
    printf("enter array size:");
    scanf("%d", &n);
    int a[n];
    int left=0,right=n-1;
    int choice;
    while (1)
    {
        printf("1.binary search inteartive\n");
        printf("2.recursive\n");
        printf("3.exit\n");
        printf("enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                printf("enter elment:");
                scanf("%d", &a[i]);
            }
            printf("enter value to find:");
            scanf("%d", &value);
            int array = binarySearchItarative(a,value, n);
            if (array == -1)
            {
                printf("not found\n");
            }
            else
            {
                printf("index at position: %d", array);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                printf("enter elment:");
                scanf("%d", &a[i]);
            }
            printf("enter value to find:");
            scanf("%d", &value);
            int array2 = binarySearchRecursive(a,left,right, value, n);
            if (array2 == -1)
            {
                printf("not found\n");
            }
            else
            {
                printf("index at position: %d\n", array2);
            }
            break;
            case 3: exit(0);
            break;
        }
    }
}