//Pramodh Krishna
//Double Linked List with min, max and duplicate

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
}*head, *tail, *nw, *temp, *temp1, *temp2;

int n; 

void creation();
void insertion();
void deletion();
void display_forwards();
void display_backwards();
void min();
void max();
void duplicate();

int main()
{
    nw = (struct node*) malloc(sizeof(struct node));
    nw->data = 0; 
    nw->next = NULL;
    nw->prev = NULL;
    int l = 1;
    n = 0;
    int choice;
    while (l == 1){
        printf("\n1.creation\n2.insertion\n3.deletion\n4.display forwards\n5.display backwards\n6.min\n7.max\n8.duplicates\n9.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            creation();
            break;
        case 2:
            insertion();
            break;
        case 3:
            deletion();
            break;
        case 4:
            display_forwards();
            break;
        case 5:
            display_backwards();
            break;
        case 6:
            min();
            break;
        case 7:
            max();
            break;
        case 8:
            duplicate();
            break;
        case 9:
            l = 0;
            break;
        default:
            printf("Number between 1 and 9");
            break;
        }
    }
    return 0;
}

void creation(){
    int item, i;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
    printf("Enter the item: ");
    scanf("%d", &item);
    if (nw->data == 0){
        nw->data = item;
        head = nw;
        tail = nw;
    }
    else{
        nw = (struct node*) malloc(sizeof(struct node));
        nw->data = item;
        tail->next = nw;
        nw->next = NULL;
        nw->prev = tail;
        tail = nw;
        
        }
    }
}


void insertion(){
    n++;
    nw = (struct node*) malloc(sizeof(struct node));
    int pos, item, i;
    printf("Enter position to insert into: ");
    scanf("%d", &pos);
    printf("Enter the item: ");
    scanf("%d", &item);
    if(pos == 1){
        nw->data = item;
        nw->next = head;
        head->prev = nw;
        head = nw;
        head->prev = NULL;
    }
    else if (pos == n){
        nw->data = item;
        tail->next = nw;
        nw->prev = NULL;
        nw->next = NULL;
        tail = nw;
    }
    else{
        temp = head;
        for (i = 0; i < pos - 2; i++)
            temp = temp->next;
        nw->data = item;
        temp1 = temp->next;
        nw->next = temp1;
        temp1->prev = nw;
        temp->next = nw;
        nw->prev = temp;
    }
}

void deletion(){
    int i, pos;
    if (n == 0){
        printf("List Empty\n");
    }
    else{
        printf("Enter the position to delete from: ");
        scanf("%d", &pos);
        if (pos == 1){
            temp = head;
            head = head->next;
            temp->next = NULL;
            head->prev = NULL;
            free(temp);
        }
        else if (pos == n){
            temp = tail;
            tail = tail->prev;
            temp->prev = NULL;
            tail->next = NULL;
            free(temp);
        }
        else{
            temp = head;
            for (i = 0; i < pos - 1; i++)
                temp = temp->next;
            temp1 = temp->next;
            temp2 = temp->prev;
            temp->prev = NULL;
            temp->next = NULL;
            temp1->prev = temp2;
            temp2->next = temp1;
            free(temp);
        }
    }
}

void display_forwards(){
    temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void display_backwards(){
    temp = tail;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
}



void min(){
    int i;
    int min = 1000;
    temp = head;
    for (i = 0; i < n; i++){
        if (temp->data <= min){
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("Min value %d\n", min);
}
void max(){
    int i;
    int max = 0;
    temp = head;
    for (i = 0; i < n; i++){
        if (temp->data >= max){
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("Max value  %d\n", max);
}


void duplicate(){
    int i, j, num, count;
    temp = head;
    while (temp != NULL){
        count = 0;
        num = temp->data;
        temp1 = temp->next;
        while(temp1 != NULL){
            if (temp1->data == num)
                count++;
            temp1 = temp1->next;
        }
        if (count >= 1){
            printf("%d\n", temp->data);
        }
        temp = temp->next;
    }
}