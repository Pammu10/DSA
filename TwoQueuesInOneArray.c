//Pramodh Krishna
//2 queues filled in 1 array from opp ends

#include <stdio.h>
#define SIZE 10
struct Twoqueues{
    int a[SIZE];
    int rear1, rear2, front1, front2;
}lq;

void enqueue1(int a);
void enqueue2(int a);
int dequeue1();
int dequeue2();
void display1();
void display2();

int main(){
    lq.front1 = -1;
    lq.front2 = SIZE;
    lq.rear1 = -1;
    lq.rear2 = SIZE;
    int choice;
    int l;
    l = 1;
        while (l == 1){
            printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch(choice){ 
                case 1:{
                int t;
                printf("number u want to queue: ");
                scanf("%d", &t);
                int c;
                printf("1.queue1\n2.queue2\n");
                scanf("%d", &c);
                if (c == 1){
                    enqueue1(t);
                    break;
                    }
                else if (c == 2){
                    enqueue2(t);
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
                    printf("1.queue1\n2.queue2\n");
                    scanf("%d", &c);
                    if (c == 1){
                        t = dequeue1();
                        printf("U popped this: %d\n", t);
                        break;
                        }
                    else if (c == 2){
                        t = dequeue2();
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
                    printf("1.queue1\n2.queue2\n");
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

void enqueue1(int b){
    if (lq.front1 == -1)
        lq.front1++;
    if (lq.rear1 < lq.rear2)
        lq.a[++lq.rear1] = b;
    else
        printf("queue1 is full\n");
}
void enqueue2(int b){
    if (lq.front2 == SIZE)
        lq.front2--;
    if (lq.rear1 < lq.rear2)
        lq.a[--lq.rear2] = b;
    else
        printf("queue2 is full\n");
}
int dequeue1(){
    if (lq.front1 > lq.rear1){
        printf("queue1 underflow\n");
        return 0;
    }
    else
        return lq.a[lq.front1++];
}
int dequeue2(){
    if (lq.front2 < lq.rear2){
        printf("queue2 underflow\n");
        return 0;
    }
    else
        return lq.a[lq.front2--];
}
void display1(){
    if (lq.front1 > lq.rear1 || lq.front1 == -1){
        printf("queue1 is empty\n");
    }
    else{
        int temp = lq.front1;
        while(temp <= lq.rear1){
            printf("%d\n", lq.a[temp++]);
        }
    }
}
void display2(){
    if (lq.front2 == SIZE || lq.front2 < lq.rear2){
        printf("queue2 is empty\n");
    }
    else{
        int temp = lq.front2;
        while(temp >= lq.rear2){
            printf("%d\n", lq.a[temp--]);
        }
    }
}