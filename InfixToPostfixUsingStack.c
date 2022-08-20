//Pramodh Krishna
//Infix-to-Postfix

#include<stdio.h>
#define size 20

char infix[size], postfix[size];
void push(int);
void post();
char pop();

struct stack
{
    int top;
    int s[size];
}st;

int main(){
    st.top = 0;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    post();
    return 0;
}

void post(){
    int i, j = 0;
    for(i=0;infix[i] != '\0';i++){
        switch (infix[i])
        {
        case '+':
            while (st.s[st.top] >= 1)
            {
                postfix[j++] = pop();
            }
            push(1);
            break;
        case '-':
            while (st.s[st.top] >= 1)
            {
                postfix[j++] = pop();
            }
            push(2);
            break;
        case '*':
            while (st.s[st.top] >= 3)
            {
                postfix[j++] = pop();
            }
            push(3);
            break;
        case '/':
            while (st.s[st.top] >= 3)
            {
                postfix[j++] = pop();
            }
            push(4);
            break;
        case '^':
            while (st.s[st.top] >= 4)
            {
                postfix[j++] = pop();
            }
            push(5);
            break;
        case '(':
            push(0);
            break;
        case ')':
            while (st.s[st.top] != 0)
            {
            postfix[j++] = pop();   
            }
            st.top--;
            break;
        default:
            postfix[j++] = infix[i]; 
        }
    }
    while(st.top > 0){
        postfix[j++] = pop();
    }
    printf("The postfix expression: ");
    printf("%s", postfix);
}

void push(int ele){
    st.top++;
    st.s[st.top] = ele;
}

char pop(){
    char e;
    int el;
    el = st.s[st.top];
    st.top--;
    switch (el)
    {
    case 1:
        e = '+';
        break;
    case 2:
        e = '-';
        break;
    case 3:
        e = '*';
        break;
    case 4:
        e = '/';
        break;
    case 5:
        e = '^';
        break;
    }
    return e;
}
