//Pramodh Krishna
//2 stacks filled in 1 array from opp ends
//Input - Whatever console asks
//output - depends on console 
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
    s.top1 = -1;
    s.top2 = 10;
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
    if (s.top1 < s.top2)
        s.a[++s.top1] = b;
    else
        printf("Stack1 is full\n");
}
void push2(int b){
    if (s.top1 < s.top2)
        s.a[--s.top2] = b;
    else
        printf("Stack2 is full\n");
}
int pop1(){
    if (s.top1 == -1){
        printf("Stack1 underflow\n");
        return 0;
    }
    else
        return s.a[s.top1--];
}
int pop2(){
    if (s.top2 == 10){
        printf("Stack2 underflow\n");
        return 0;
    }
    else
        return s.a[s.top2++];
}
void display1(){
    if (s.top1 == -1){
        printf("Stack1 is empty\n");
    }
    else{
        int temp = s.top1;
        while(temp > -1){
            printf("%d\n", s.a[temp]);
            temp--;
        }}
}
void display2(){
    if (s.top2 == 10){
        printf("Stack2 is empty\n");
    }
    else{
        int temp = s.top2;
        while(temp < 10){
            printf("%d\n", s.a[temp]);
            temp++;
        }}
}