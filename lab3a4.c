#include <stdio.h>
int main()
{
    int a;
    printf("enter array size:");
    scanf("%d", &a);
    int arr[a];

    for (int i = 0; i < a; i++)
    {
        printf("enter array element:");
        scanf("%d", &arr[i]);
    }
    int max = arr[0], index = 0;
    int min = arr[0], count = 0;
    for (int j = 0; j < a; j++)
    {
        if (arr[j] > max)
        {
            max = arr[j];
            index++;
        }
        if (arr[j] < min)
        {
            min = arr[j];
            count++;
        }
    }

    printf("largest :%d\n", max);
    printf("smallest :%d\n", min);
    printf("largest position:%d\n", count);
    printf(" smallest position:%d", index);
}