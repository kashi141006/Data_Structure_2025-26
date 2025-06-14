#include <stdio.h>
int main(){
    int a;
    printf("enter array size:");
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
   printf("enter aray element:");
       scanf ("%d",&arr[i]);
    }
     for(int i=0;i<a;i++){

       printf("%d ",arr[i]);
    }
    return 0;
}