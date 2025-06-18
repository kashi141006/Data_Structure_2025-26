#include <stdio.h>
void main() w
{
    int a[2][2], b[2][2], c[2][2];

    printf("first matrix:");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("enter element:");
            scanf("%d", &a[i][j]);
        }
    }
    printf("second matrix:");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("enter element:");
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
         c[i][j]=a[i][j]+b[i][j];
         
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
          printf("%d ",c[i][j]);
         
        }
        printf(" \n");
    }
}