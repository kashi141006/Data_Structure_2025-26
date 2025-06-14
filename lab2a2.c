#include <stdio.h>
int main()
{
    int base, exe, ans=1;
    printf("enter base:");
    scanf("%d", &base);
    printf("enter expontecial:");
    scanf("%d", &exe);
    for (int i = 1; i<=exe; i++)
    {

        ans = base * ans;
    }
    printf("power:%d", ans);
}