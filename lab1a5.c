 #include<stdio.h>
#include<math.h>
int main(){
 int year;
 printf("enter year:");
 scanf("%d",&year);
 if((year%4==0 && year%100!=0)||year%400==0){
     printf("year is leap year");
 }
    else{
        printf("year is not leap year");
    }
    return 0;
}