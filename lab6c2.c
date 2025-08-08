#include <stdio.h>
#include <string.h>
int s[100][2];
int top = -1;
void push(int start, int end)
{
    top++;
    s[top][0] = start;
    s[top][1] = end;
}
int pop(int x)
{
    if (top >= 0)
    {
        int value = s[top][x];
        if (x == 1)
        {
            top--;
        }
        return value;
    }
    else
    {
        return -1;
    }
}
void mergeInterl(int a[][2], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j][0] > a[j + 1][0])
            {
                temp = a[j][0];
                a[j][0] = a[j + 1][0];
                a[j + 1][0] = temp;

                temp = a[j][1];
                a[j][1] = a[j + 1][1];
                a[j + 1][1] = temp;
            }
        }
    }
}
void main()
{
    int a[100][2];
    int n;
    printf("enter number of interval:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

        printf("enter Interval element:");
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    mergeInterl(a, n);
    for (int i = 0; i < n; i++)
    {
        if (top == -1)
        {
            push(a[i][0], a[i][1]);
        }
        else
        {
            int topstart = s[top][0];
            int topend = s[top][1];
            if (a[i][0] <= topend)
            {
                if (a[i][1] > topend)
                {
                    s[top][1] = a[i][1];
                }
            }
            else
            {
                push(a[i][0], a[i][1]);
            }
        }
    }
    printf("!---------merged interval-----------!\n");
    for (int i = 0; i <= top; i++)
    {

        printf("{%d,%d}\n", s[i][0], s[i][1]);
    }
    printf("!------------------------------------!\n");
}