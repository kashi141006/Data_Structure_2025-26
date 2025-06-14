 #include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    printf("enter a:");
    scanf("%d",&a);
    printf("enter b:");
    scanf("%d",&b);
    printf("enter c:");
    scanf("%d",&c);
    if(a>b && a>c ){
         
            printf("a is largest");
        }
        else if(b>c && b>a){
            printf("b is largest");
        }
        else{
            printf("c is largest")
        }
    
    
    return 0;
}