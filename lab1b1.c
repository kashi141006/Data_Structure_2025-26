 #include<stdio.h>
#include<math.h>
int main(){
    int ts,hh,mm,ss;
    printf("enter second:");
    scanf("%d",&ts);
    hh=ts/3600;
    mm=ts/60-hh*60;
    ss=ts-hh*60*60-mm*60;
    
    printf("hh:%d mm:%d ss:%d",hh,mm,ss);
    
    return 0;
}