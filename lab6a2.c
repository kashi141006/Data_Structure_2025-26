#include <stdio.h>
#include <stdlib.h>
 
char s[100];
int top = 0;
 
void push(char x)
{
    

    s[++top] = x;
}
char pop()
{ 
    return s[top--];
}
void recognize(char str[])
{
 top=1;
    int i = 0;
    push('c');
    char next;
    next = str[0];

    while (next != 'c')
    {
        if (next=='\0')
        {
            printf("invalid");
            return;
        }
        else
        {
            push(next);
            i++;
            next = str[i];
        }
    }
    while (s[top] != 'c')
    {
        i++;
        next = str[i];
        char x = pop();
        if (next != x)
        {
            printf("invalid");
           return;
        }
    }
    i++;
    next = str[i];
    if (next=='\0')
    {
        printf("valid");
    }
    else
    {
        printf("invalid");
    }
}

 
 
int main()
{
     
    char ch[100];
    printf("enter string:");
    scanf("%s",ch);
    recognize(ch);
}