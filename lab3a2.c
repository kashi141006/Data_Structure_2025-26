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
    int s,e,sum=0;
    printf(" start and end point:");
    scanf("%d %d",&s,&e);
    for(int j=s-1;j<e;j++){
        sum+=arr[j];

    }
    printf(" sum :%d ",sum);



return 0;
}