#include <stdio.h>
int main()
{
    int a;
    printf("enter array size:");
    scanf("%d", &a);
    int arr[a];

    for (int i = 0; i < a; i++)
    {
        printf("enter aray element:");
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        sum += arr[i];
    }
    float average;
    average=(float)sum/a;

    printf(" sum :%d ", sum);
    printf(" average :%f ",average);

    return 0;
}