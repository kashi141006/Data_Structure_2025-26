 #include<stdio.h>
#include<math.h>
int main(){
 int  td,year,week,day;
 printf("enter total days:");
 scanf("%d",&td);
  year=td/365;
  week=(td%365)/7;
  day=td-week*7-year*365;
  printf("year:%d week:%d day:%d",year,week,day);
    return 0;
}