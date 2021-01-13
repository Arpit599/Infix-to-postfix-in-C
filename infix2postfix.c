#include<stdio.h>
#include<string.h>

char stack[100];
int top = -1;

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    else if(op == '/' || op == '*')
        return 2;
    else if(op == '^')
        return 3;
    else 
        return -1;
}

char pop()
{
    if (top == -1)
        return NULL;
    return stack[top--];
}

void push(char element)
{
    stack[++top] = element;
}

int main(void)
{
    char exp[100];
    printf("Enter the expression : ");
    scanf("%s", exp);

    int len = strlen(exp);
    for(int i = 0; i < len; i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
            printf("%c", exp[i]);
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            while(stack[top] != '(')
            {
                char c = pop();
                printf("%c", c);
            }
            pop();
        }
        else
        {
            while (top != -1 && (precedence(exp[i]) <= precedence(stack[top])))
            {
                if (stack[top] == '(')
                {
                    char c = pop();
                    break;
                }
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }

    while(top != -1)
        printf("%c", stack[top--]);
    
    return 0;
}