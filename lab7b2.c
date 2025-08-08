#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
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
void evalute_prifix(char prifix[])
{
    char temp;
    int i , value = 0;
     for(i=strlen(prifix)-1;i>=0;i--)
    {
        
        if (isdigit(prifix[i]))
        {
            push(prifix[i]-'0');
        }
        else
        {
            int operand1 = pop();
            int operand2 = pop();
            switch (prifix[i])
            {
            case '+':
             push(operand1 + operand2);
                 break;
            case '-':
                push(operand1 - operand2);
                break;

            case  '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
                  case '^':
                push(pow(operand1,operand2));
                break;
            }
        }
         
    }
     printf("%d",pop());
    
}
void main()
{
    char str[100];
    printf("enter a string:");
    scanf("%s", str);
    evalute_prifix(str);
}