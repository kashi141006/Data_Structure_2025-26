 #include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("enter number:");
    scanf("%d",&n);
    if(n%2==0){
        printf("number is even");
    }
    else{
        printf("number is odd");
    }
    return 0;
}