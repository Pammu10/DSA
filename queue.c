#include<stdio.h>
#define size 20

struct queue
{
    int front, rear;
    int a[size];
}lq;

void enqueue(int);
int dequeue();
void display();

int main(){
    lq.front = -1;
    lq.rear = -1;
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
    if (lq.front == -1 && lq.rear == -1){
        lq.front++;
        lq.rear++;
        lq.a[lq.rear++] = ele;
    }
    else{
        lq.a[lq.rear++] = ele;
    }
}
int dequeue(){
    if (lq.front == -1 && lq.rear == -1){
        printf("Queue is empty");
        return 0;
    }
    else if (lq.front == 0 && lq.rear == 0){
        lq.rear--;
        return lq.a[lq.front++];
    }
    else{
        return lq.a[lq.front++];
    }
}

void display(){
    if (lq.front == -1 && lq.rear == -1){
        printf("Queue is empty");
    }
    else if(lq.front == 0 && lq.rear == 0){
        printf("%d\n", lq.a[0]);
    }
    else{
        int temp = lq.front;
        while(temp < lq.rear){
        printf("%d\n", lq.a[temp++]);
    }
    }
}
