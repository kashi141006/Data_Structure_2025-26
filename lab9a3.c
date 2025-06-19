#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("enter array element:");
    scanf("%d",&n);
     
    int *a=(int*)calloc(n,sizeof(int));
   
   
    for(int i=0;i<n;i++){
        printf("enter element:");
        scanf("%d",a+i);
    }
    int sum=0;
    for(int i=0;i<n;i++){

        printf("%d",*(a+i));
        sum+=*(a+i);
    }
 printf("sum:%d ",sum);

  return 0;
}