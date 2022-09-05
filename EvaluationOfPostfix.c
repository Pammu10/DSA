//Pramodh Krishna
//Evaluation of Postfix

#include<stdio.h>
#include <ctype.h>
#define size 20

char postfix[size];
void push(int);
void post();
int pop();

struct stack
{
    int top;
    int s[size];
}st;

int main(){
    st.top = 0;
    char ch;
    int a, b, val;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    for (int i = 0; postfix[i] != '\0'; i++){
        ch = postfix[i];
        if (isdigit(ch)){
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            a = pop();
            b = pop();
            switch(ch)
            {
            case '*':
                val = b * a;
                break;

            case '/':
                val = b / a;
                break;

            case '+':
                val = b + a;
                break;

            case '-':
                val = b - a;
                break;
            }
            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
    return 0;
}

void push(int ele){
    st.top++;
    st.s[st.top] = ele;
}

int pop(){
    int el = st.s[st.top];
    st.top--;
    return el;
}