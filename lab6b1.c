#include <stdio.h>
#include <string.h>
int top = -1;
char s[100];
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
    if (top < 0)
    {
        printf("underflow\n");
    }
    else
    {
        return s[top--];
    }
}
void isEqual(char str[])
{
    int i = 0;
    int length = strlen(str);
    while (str[i] == 'a')
    {
        push('a');
        i++;
    }
    while (str[i] == 'b')
    {
       
         if(top<0){
               break;
         }
        pop();

        i++;
    }

    if (top == -1 && i == length)
     
    {
        printf("the string of  the form of a^i b^i \n");
    }
    else
    {
        printf("the string of the form of not a^i b^i \n");
    }
}
void main()
{
    char s1[100];
    printf("enter string:");
    scanf("%s", s1);
   isEqual(s1);
    
}