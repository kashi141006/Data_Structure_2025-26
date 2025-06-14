#include<stdio.h>
int main(){
    int n,sum=0,count=0;
    printf("enter number:");
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++){
  count=count+i;
  sum=sum+count;
 
    }
    printf("%d",sum);
}