#include<stdio.h>
 int main()
{
    int a;
    printf("enter array size:");
    scanf("%d", &a);
    int arr[a];
    int num;
    for (int i = 0; i < a; i++)
    {
        printf("enter array element:");
        scanf("%d", &arr[i]);
    }
    int n1, r;
int index;
    printf("enter number with replace number:");
    scanf("%d %d",&n1,&r);
     for (int i=0;i<a;i++){
        if(r==arr[i]){
            arr[i]=n1;
            index=i;

        }
     }
     for(int i=0;i<a;i++){
        printf("%d\n",arr[i]);

     }
}