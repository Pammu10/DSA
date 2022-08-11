// Pramodh Krishna
// Stack
/*
#include <stdio.h>
struct Stack{
    int a[5];
    int top;
}s;

void push(int a);
int pop();
void display();

int main(){
    s.top = -1;
    int choice;
    int l;
    l = 1;
        while (l == 1){
            printf("1. push\n2. pop\n3. display\n4. exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){ 
                case 1:{
                int t;
                printf("Enter the number u want to push: ");
                scanf("%d", &t);
                push(t);
                break;
            }
                case 2:{
                int t = pop();
                printf("U popped this: %d\n", t);
                break;
            }
                case 3:{
                display();
                break;
            }
                case 4:{
                l = 0;
                break;
            }
        }

    }
    return 0;
}

void push(int b){
    if (s.top != 4)
        s.a[++s.top] = b;
    else
        printf("Stack is full\n");
}
int pop(){
    if (s.top == -1){
        printf("Stack underflow\n");
        return 0;
    }
    else
        return s.a[s.top--];
}
void display(){
    if (s.top == -1){
        printf("Stack is empty\n");
    }
    else{
        int temp = s.top;
        while(temp > -1){
            printf("%d\n", s.a[temp]);
            temp--;
        }}
}
*/

//Pramodh Krishna
//2 Stacks using array
/*
#include <stdio.h>
struct Twostacks{
    int a[10];
    int top1, top2;
}s;

void push1(int a);
void push2(int a);
int pop1();
int pop2();
void display1();
void display2();

int main(){
    s.top1 = 5;
    s.top2 = 4;
    int choice;
    int l;
    l = 1;
        while (l == 1){
            printf("1. push\n2. pop\n3. display\n4. exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){ 
                case 1:{
                int t;
                printf("number u want to push: ");
                scanf("%d", &t);
                int c;
                printf("1.stack1\n2.stack2\n");
                scanf("%d", &c);
                if (c == 1){
                    push1(t);
                    break;
                    }
                else if (c == 2){
                    push2(t);
                    break;
                    }
                else{
                    printf("Invalid input\n");
                    break;
                    }
            }
                case 2:{
                    int c;
                    int t;
                    printf("1.stack1\n2.stack2\n");
                    scanf("%d", &c);
                    if (c == 1){
                        t = pop1();
                        printf("U popped this: %d\n", t);
                        break;
                        }
                    else if (c == 2){
                        t = pop2();
                        printf("U popped this: %d\n", t);
                        break;
                    }
                else{
                        printf("Invalid input\n");
                        break;
                    }
            }
                case 3:{
                    int c;
                    printf("1.stack1\n2.stack2\n");
                    scanf("%d", &c);
                    if (c == 1){
                        display1();
                        break;
                        }
                    else if (c == 2){
                        display2();
                        break;
                    }
                else{
                        printf("Invalid input\n");
                        break;
                    }
            }
                case 4:{
                l = 0;
                break;
            }
        }

    }
    return 0;
}

void push1(int b){
    if (s.top1 > -1)
        s.a[--s.top1] = b;
    else
        printf("Stack is full\n");
}
void push2(int b){
    if (s.top2 < 10)
        s.a[++s.top2] = b;
    else
        printf("Stack is full\n");
}
int pop1(){
    if (s.top1 == 5){
        printf("Stack underflow\n");
        return 0;
    }
    else
        return s.a[s.top1++];
}
int pop2(){
    if (s.top2 == 4){
        printf("Stack underflow\n");
        return 0;
    }
    else
        return s.a[s.top2--];
}
void display1(){
    if (s.top1 == 5){
        printf("Stack is empty\n");
    }
    else{
        int temp = s.top1;
        while(temp < 5){
            printf("%d\n", s.a[temp]);
            temp++;
        }}
}
void display2(){
    if (s.top2 == 4){
        printf("Stack is empty\n");
    }
    else{
        int temp = s.top2;
        while(temp > 4){
            printf("%d\n", s.a[temp]);
            temp--;
        }}
}
*/

//Pramodh Krishna
//Infix-to-Postfix
/*
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
*/
//Pramodh Krishna
//Infix-to-prefix
/*
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
*/