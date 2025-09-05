
#include <stdio.h>
#include <stdlib.h>
int quick(int a[], int size, int lb, int ub)
{
    int flag = 1;
    int j;
    int i = lb;
    j = ub + 1;
    int key = a[lb];
    if (lb < ub)
    {

        while (flag == 1)
        {
            i++;
            while (a[i] < key)
            {
                i++;
            }
            j--;
            while (a[j] > key )
            {
                j--;
            }

            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else
            {
                flag = 0;
            }
        }
        int temp2 = a[lb];
        a[lb] = a[j];
        a[j] = temp2;
        return quick(a, size, l-b, j);
        return quick(a, size, j + 1, ub);
    }
}

void main()
{
    int n, value;
    int lb = 0;
    printf("enter array size:");
    scanf("%d", &n);
    int a[n];
    int ub = n - 1;
    for (int i = 0; i < n; i++)
    {
        printf("enter elment:");
        scanf("%d", &a[i]);
    }

    quick(a, n, lb, ub);
    printf("!---------sorted array-------!\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d   ", a[i]);
    }
}