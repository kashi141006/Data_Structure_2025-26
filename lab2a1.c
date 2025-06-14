#include <stdio.h>
int fact();
int main(){
    int n,ans;
    printf("enter number:");
    scanf("%d",&n);
 ans=fact(n);
 printf("factorial=%d",ans);
 return 0;
}
int fact(int n){
    if(n==1){
        return 1;
    }else{
        return n*fact(n-1);
    }
}