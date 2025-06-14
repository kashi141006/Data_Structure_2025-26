#include <stdio.h>
int main()
{
    int n,rev;
    printf("enter number:");
    scanf("%d",&n);
    int temp=n;
     int sum=0;
    while(n!=0){
        rev=n%10;
        sum=sum*10+rev;
        n=n/10;
 
    }
   printf("reverse:%d",sum);

 
}