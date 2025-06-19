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
     
   int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(a+j)>*(a+j+1)){
           temp=*(a+j);
           *(a+j)=*(a+j+1);
           *(a+j+1)=temp;
        }
    }
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(a+i));
    }
  return 0;
}