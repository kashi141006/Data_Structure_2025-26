#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n;
    printf("enter size:");
    scanf("%d", &n);
    char *str = (char *)calloc(n + 1, sizeof(char));

    printf("enter string:");
    scanf("%s", str);
   
int len=strlen(str);
   int flag=0;

    for (int i = 0; i < len / 2; i++)
    {  
        char *start=str+i;
        char *end=str+len-i-1;

 if(*start!=*end){
    flag=1;
    break;
    
 }
    }
    if(flag==0){
        printf("Palindrome\n");
    }else{
        printf("not palindrome");
    }
}