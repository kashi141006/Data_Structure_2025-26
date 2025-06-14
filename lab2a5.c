#include<stdio.h>
int main(){
    int n,count=0;
    printf("enter number:");
    scanf("%d",&n);
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
             count++;
            
        }
        else{
   break;
        }
       
    }
    if(count==0 || n==1){
      printf("number is prime");
    }
    else{
        printf("number is not prime");
    }
}