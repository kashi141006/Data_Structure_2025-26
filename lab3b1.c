#include <stdio.h>
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
    int count=0;
     num=arr[0];{
        for(int i=0;i<a;i++){
            if(num==arr[i]){
                 
                count=0;
            }
             
        }
        if(count==0){
            printf("numer is duplicate");
        }
        else{
            printf("numer is not duplicate");
        }
    }
}