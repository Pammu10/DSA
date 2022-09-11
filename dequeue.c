#include<stdio.h>
#define SIZE 10

struct dequeue{
    int a[SIZE];
    int front, rear;
}dq;

void insert_end();
void insert_start();
int delete_end();
int delete_start();
void display();


int main()
{
    dq.rear = -1;
    dq.front = -1;
    int choice, l = 0;
    while (l == 0){
        printf("1.Insert at the end\n2.Delete at the front\n3.Insert at the front\n4.Delete at the end\n5.display\n6.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_end();
            break;
        case 2:
            delete_start();
            break;
        case 3:
            insert_start();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            display();
            break;
        case 6:
            l = 1;
            break;
        default:
            break;
        }
    }
    return 0;
}


void insert_end(){
    int item;
    printf("Enter the item you want to insert: ");
    scanf("%d", &item);
    
    if ((dq.front == 0 && dq.rear == SIZE - 1) || dq.front == dq.rear + 1){
        printf("Queue Overflow");
    }
    
    else if(dq.rear == SIZE - 1){
        dq.rear = 0; 
        dq.a[dq.rear] = item;
    }
    else {
        dq.a[++dq.rear] = item;
    }
    if (dq.front == -1)
        dq.front++;
    
}

int delete_start(){
    int item;
    if (dq.front == -1 && dq.rear == -1){
        printf("Queue underflow\n");
        return 0;
    }
    else if(dq.front == dq.rear){
        item = dq.front;
        dq.front = -1;
        dq.rear = -1;
    }
    else if (dq.front == SIZE - 1){
        item = dq.a[dq.front];
        dq.front = 0;
    }
    else{
        item = dq.a[dq.front++];
    }
}

void display(){
    int temp = dq.front;
    while (temp != dq.rear + 1){
        
        printf("%d\t", dq.a[temp++]);
        if (temp == SIZE){
            temp =0;
        }
    }
    printf("\n");
}

void insert_start(){
    int item;
    printf("Enter the item you want to insert: ");
    scanf("%d", &item);
    if (dq.front == 0 || dq.front == -1){
        dq.front = SIZE-1;
        dq.a[dq.front] = item;
    }
    else if (dq.front == dq.rear + 1){
        printf("Queue overflow\n");
    }
    else {
        dq.a[--dq.front] = item;
    }

}

int delete_end(){
    int item;
    if (dq.front == -1 && dq.rear == -1){
        printf("Queue underflow\n");
        return 0;
    }
    else if(dq.front == dq.rear){
        item = dq.rear;
        dq.front = -1;
        dq.rear = -1;
    }
    else if (dq.rear == 0){
        item = dq.a[dq.rear];
        dq.rear = SIZE-1;
    }
    else{
        item = dq.a[dq.rear--];
    }
}