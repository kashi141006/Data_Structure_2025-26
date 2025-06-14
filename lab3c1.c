#include <stdio.h>
int main(){
    int n;
    printf("enter row:");
    scanf("%d",&n);
    
    int i,j;
     int ans=1;
    for( i=0;i<n;i++){
       
        for( j=0;j<n-i;j++){
            printf(" ");
        }
        for(j=0;j<=i;j++){
         if(j==0 || i==0){
         ans=1;
         }
         else{ 
            ans=ans*(i-j+1)/j;
         }
         printf("%d ",ans);
        }
        printf("\n");
    }
     
    
}