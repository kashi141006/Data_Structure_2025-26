#include <stdio.h>
#include <string.h>
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
int stack_Pre(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 3;
    }
    else if (c == '^')
    {
        return 6;
    }
    else if (c == '(')
    {
        return 0;
    }
    else
    {
        return 8;
    }
}
int input_Pre(char c)
{
    if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/')
    {
        return 4;
    }
    else if (c == '^')
    {
        return 5;
    }
    else if (c == '(')
    {
        return 9;
    }
    else if (c == ')')
    {
        return 0;
    }

    else
    {
        return 7;
    }
}
int rank(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
void infixtoPrifix(char infix[])
{
    char temp;
    int r = 0;
    push('(');
    char polish[100];
    int i = 0, j = 0;
    char next;
    while ( i!=strlen(infix))
    {
        next = infix[i];
        
        if (top < 0)
        {
            printf("invalid\n");
        }
        while (stack_Pre(s[top]) > input_Pre(next))
        {
            temp = pop();
            polish[j++] = temp;
            r = r + rank(temp);
            if (r < 1)
            {
                printf("invalid\n");
            }
        }
        if (stack_Pre(s[top]) != input_Pre(next))
        {
            push(next);
        }
        else
        {
            temp = pop();
        }
        i++;
    }
    polish[j] = '\0';
    if (top != -1 || r != 1)
    {
        printf("invalid\n");
    }
    else
    {
        printf("%s", strrev(polish));
    }
}
void main()
{
    char str[100];
    char rev[100];

    int i=0,j=0;
    printf("enter a string:");
    scanf("%s",str);
    
    for(int i=strlen(str)-1;i>=0;i--){
        if(str[i]=='('){
            rev[j++]=')';
        }
        else if (str[i]==')')
        {
            rev[j++]='(' ;
        }
        else{
            rev[j++]=str[i];
        }
    }
    rev[j]='\0';
    strcat(rev,")");
    infixtoPrifix(rev);
}