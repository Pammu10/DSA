//Pramodh Krishna
//Evaluation of Prefix

#include<stdio.h>
#include <ctype.h>
#include<string.h>

#define size 20

char prefix[size];
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
    scanf("%s", prefix);
    for (int i = strlen(prefix) - 1; i >= 0; i--){
        ch = prefix[i];
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