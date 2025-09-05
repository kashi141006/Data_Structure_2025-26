
#include <stdio.h>
#include <stdlib.h>

int insertion(int a[], int size)
{
    int i = 1;
    int key;
    while (i < size)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            int temp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = temp;
            j--;
        }
        int temp2 = a[j + 1];
        a[j + 1] = key;
        key = temp2;

        i++;
    }

    printf("!---------sorted array-------!\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d   ", a[i]);
    }
}
void main()
{
    int n, value;
    printf("enter array size:");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter elment:");
        scanf("%d", &a[i]);
    }

    insertion(a, n);
}