//Pramodh Krishna
//21BIT0510
//Queues using Linked List

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
}*nw, *front, *rear, *temp;


void enqueue(int);
void dequeue();
void display();

int main()
{
    nw = (struct node*) malloc(sizeof(struct node));
    front = nw;
    rear = nw;
    nw->data = 0;
    front->next = NULL;
    int l = 1;
    int choice;
    

    while (l == 1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter ur choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int item;
            printf("Enter the item u want to push");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            l = 0;
            break;
        default:
            printf("Enter no btw 1 and 4\n");
            break;
        }
    }
    return 0;
}


void enqueue(int item){
    if (rear->data == 0)
        rear->data = item;
    else{
    nw = (struct node*) malloc(sizeof(struct node));
    nw ->next = NULL;
    rear->next = nw;
    rear = nw;
    rear -> data = item;
    if (front == NULL)
        front = nw;
    }
}

void dequeue(){
    if (front != NULL){
        printf("%d", front->data);
        front = front->next;
    }
    else {
        printf("Stack underflow");
    }
}

void display(){
    temp = front;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
