
#include <stdio.h>
#include <stdlib.h>

int selection(int a[], int size)
{

    for (int i = 0; i < size - 2; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex !=i){
        int temp=a[i];
        a[i]=a[minIndex];
        a[minIndex]=temp;
        }
         
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

    selection(a, n);
}