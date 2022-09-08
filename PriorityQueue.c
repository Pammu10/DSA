//Pramodh Krishna 
//Priority Queue using linked list

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    int priority;
    struct node* next;
};

struct node *front, *rear, *temp, *temp1, *nw;
int count;

void creation();
void enqueue(int, int);
void sort();
int dequeue();
void display();

int main(){
    count = 0;
    creation();
    int choice, l = 0;
    do{
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        int item, pit;
            printf("Enter value and priority: ");
            scanf("%d %d", &item, &pit);
            enqueue(item, pit);
            break;
        case 2:
            printf("Task with highest priority dequeued: %d\n", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            l = 1;
            break;
        default:
            break;
        }
    } while(l == 0);
    return 0;
}


void creation(){
    nw = (struct node*) malloc(sizeof(struct node));
    nw->next = NULL;
    front = nw;
    rear = nw;
    nw->data = 0;
    nw->priority = 0;
    count++;
}
void enqueue(int d, int p){
    if (nw->data == 0){
        nw->data = d;
        nw->priority = p;
    }
    else{
        count++;
        nw = (struct node*) malloc(sizeof(struct node));
        nw->data = d;
        nw->priority = p;   
        rear->next = nw;
        rear = nw;
        nw->next = NULL;                                                                                                 
    }
    sort();
}

void sort(){
    if (count == 0){
        printf("Queue empty");
    }
    else {
        temp = front;
        for (int i = 0; i < count - 1; i++){
            temp1 = temp->next;
            for (int j = i + 1; j < count; j++){
                if (temp->priority < temp1->priority){
                    int tempie = temp->data;
                    temp->data = temp1->data;
                    temp1->data = tempie;
                    tempie = temp->priority;
                    temp->priority = temp1->priority;
                    temp1->priority = tempie;
                }
                temp1 = temp1->next;
            }
                
            temp = temp->next;
        }
        

    }
}

int dequeue(){
    if (count == 0){
        printf("Queue is empty");
        return 0;
    }
    else{
        count--;
        int item = front->data;
        front = front->next;
        return item;
    }
}

void display(){
    temp = front;
    for (int i = 0; i < count; i++){
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}
