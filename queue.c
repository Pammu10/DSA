//Pramodh Krishna 
//21BIT0510
#include<stdio.h>
#define size 5

int count;
struct queue
{
    int front, rear;
    int a[size];
}lq;

void enqueue(int);
int dequeue();
void display();

int main(){
    lq.front = 0;
    lq.rear = -1;
    count = 0;
    int choice;
    int l = 1;
    while (l==1)
    {
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        int item;
        printf("Enter the element u want to queue: ");
        scanf("%d", &item);
        enqueue(item);
        break;
    case 2:
        printf("U dequeued this: %d\n", dequeue());
        break;
    case 3:
        display();
        break;
    case 4:
        l = 0;
        break;
    default:
        printf("Error, Enter a number from 1 to 4");
        break;
    }
    }
    return 0;
}

void enqueue(int ele){
    if (count < size){
    if (lq.rear == size){
        lq.rear = -1;
        lq.a[++lq.rear] = ele;
        count++;
    }
    else{
        lq.a[++lq.rear] = ele;
        count++;
    }
}
    else {
        printf("Queue is full\n");
    }
}
int dequeue(){
    int data;
    if (count == 0){
        printf("Queue is empty\n");
        data = 0;
    }
    else if (lq.front == size){
        data =  lq.a[lq.front];
        lq.front = 0;
        count--;
    }
    else{
        data =  lq.a[lq.front++];
        count--;
    }
    return data;
}

void display(){
    if (count == 0){
        printf("Queue is empty\n");
    }
    else{
        int temp = lq.front;
        int m = 0;
        while(m++ < count){
        printf("%d\n", lq.a[temp++]);
        if (temp == size){
            temp = 0;
        }
    }
    }
}
