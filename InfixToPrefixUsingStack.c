//Pramodh Krishna
//Infix-to-prefix

#include<stdio.h>
#include<string.h>
#define size 20

char infix[size], prefix[size], rev[size];
void push(int);
void pfix();
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
    strcpy(rev, strrev(infix));
    pfix();
    return 0;
}
void pfix(){
    int i, j = 0;
    for(i=0;rev[i] != '\0';i++){
        switch (rev[i])
        {
        case '+':
            while (st.s[st.top] >= 1)
            {
                prefix[j++] = pop();
            }
            push(1);
            break;
        case '-':
            while (st.s[st.top] >= 1)
            {
                prefix[j++] = pop();
            }
            push(2);
            break;
        case '*':
            while (st.s[st.top] >= 3)
            {
                prefix[j++] = pop();
            }
            push(3);
            break;
        case '/':
            while (st.s[st.top] >= 3)
            {
                prefix[j++] = pop();
            }
            push(4);
            break;
        case '^':
            while (st.s[st.top] >= 4)
            {
                prefix[j++] = pop();
            }
            push(5);
            break;
        case ')':
            push(0);
            break;
        case '(':
            while (st.s[st.top] != 0)
            {
            prefix[j++] = pop();   
            }
            st.top--;
            break;
        default:
            prefix[j++] = rev[i]; 
        }
    }
    while(st.top > 0){
        prefix[j++] = pop();
    }
    printf("The prefix expression: ");
    printf("%s", strrev(prefix));
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
