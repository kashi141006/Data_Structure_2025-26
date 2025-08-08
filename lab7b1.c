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
void evalute_postfix(char postfix[])
{
    char temp;
    int i = 0, value = 0;
    while (postfix[i] != '\0')
    {
        temp = postfix[i];
        if (isdigit(temp))
        {
            push(postfix[i]-'0');
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            switch (postfix[i])
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
        i++;
    }
     printf("%d",pop());
    
}
void main()
{
    char str[100];
    printf("enter a string:");
    scanf("%s", str);
    evalute_postfix(str);
}