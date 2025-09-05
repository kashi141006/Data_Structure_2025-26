
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int a[], int low, int mid, int high)
{
    int h, i, j, k;
    int b[5];
    h = low;
    i = low;
    j = mid + 1;

    while (h <= mid && j <= high)
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (k = low; k <= high; k++)
    {
        a[k] = b[k];
    }
     
     
}
void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = floor((low + high) / 2);
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    int n, value;
    int low = 0;
    printf("enter array size:");
    scanf("%d", &n);
    int a[n];
    int high = n - 1;
    for (int i = 0; i < n; i++)
    {
        printf("enter elment:");
        scanf("%d", &a[i]);
    }

    mergesort(a, low, high);
    for (int i = 0; i < n; i++)
    {

        printf("%d   ", a[i]);
    }

    return 0;
}