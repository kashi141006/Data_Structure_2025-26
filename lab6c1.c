#include<stdio.h>
#include<string.h>
char s[100];
int top = -1;

void push(char ch)
{
    if (top >= 99)
    {
        printf("stack overflow\n");
    }
    else
    {
        s[++top] = ch;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        return s[top--];
    }
}

void removeStar( char ch[])
{
    for(int i=0;ch[i]!='\0';i++){
        if(ch[i]!='*'){
            push(ch[i]);
        }else{
            pop();
        }
    }
    s[top+1]='\0';
    
    printf("Output:%s\n",s);
}
void main()
{
    char str[100];
    printf("enter a string:");
    scanf("%s", str);
    removeStar(str);
}