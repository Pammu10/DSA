//Pramodh Krishna
//Stack

#include<stdio.h>
#define size 20

void push(int);
void display();
int pop();

struct stack
{
    int top;
    int s[size];
}st;

int main(){
    st.top = -1;
    int choice;
    int l = 1;
    while(l == 1){
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int item;
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2: 
                item = pop();
                printf("Popped item: %d", item);
                break;
            case 3:
                display();
                break;
            case 4:
                l = 0;
                break;
            default:
                printf("Enter number between 1 and 4");
                break;
        }
    }
    return 0;
}


void push(int ele){
    if (st.top <= size)
        st.s[++st.top] = ele;
    else
        printf("Stack full");
}

int pop(){
    int item;
    if (st.top == -1)
        printf("Stack empty");
    else
        item = st.s[st.top--];
    return item;
}

void display(){
    int temp = st.top;
    while(temp != -1){
        printf("%d\n", st.s[temp--]);
    }
}
