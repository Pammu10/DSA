//Pramodh Krishna
//Linked List and merging of two linked lists
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
}*head, *tail, *nw, *temp, *temp1, *head1, *tail1;

int n, n1; 

void creation();
void insertion();
void deletion();
void display();
bool isEmpty();
void makeEmpty();
void search();
void count();
void merge();

int main()
{
    nw = (struct node*) malloc(sizeof(struct node));
    nw->data = 0; 
    nw->next = NULL;
    int l = 1;
    n = 0;
    n1 = 0;
    int choice;
    while (l == 1){
        printf("\n1.creation\n2.insertion\n3.deletion\n4.display\n5.count\n6.search\n7.empty\n8.merge\n9.exit\n");
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
            display();
            break;
        case 5:
            count();
            break;
        case 6:
            search();
            break;
        case 7:
            makeEmpty();
            break;
        case 8:
            merge();
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
        tail = nw;
    }
    }
}

void creation1(){
    nw = (struct node*) malloc(sizeof(struct node));
    nw->next = NULL;
    nw->data = 0;
    int item, i;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++){
    printf("Enter the item: ");
    scanf("%d", &item);
    if (nw->data == 0){
        nw->data = item;
        head1 = nw;
        tail1 = nw;
    }
    else{
        nw = (struct node*) malloc(sizeof(struct node));
        nw->data = item;
        tail1->next = nw;
        nw->next = NULL;
        tail1 = nw;
    }
    }
}

bool isEmpty(){
    if (head->next = NULL)
    return true;
    else 
    return false;
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
        head = nw;
    }
    else if (pos == n){
        nw->data = item;
        tail->next = nw;
        nw->next = NULL;
        tail = nw;
    }
    else{
        temp = head;
        for (i = 0; i < pos - 2; i++)
            temp = temp->next;
        nw->data = item;
        nw->next = temp->next;
        temp->next = nw;
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
            free(temp);
        }
        else if (pos == n){
            temp = head;
            for (i = 0; i < pos - 2; i++)
                temp = temp->next;
            tail = temp;
            temp1 = temp->next;
            tail->next = NULL;
            free(temp1);
        }
        else{
            temp = head;
            for (i = 0; i < pos - 2; i++)
                temp = temp->next;
            temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = NULL;
            free(temp1);
        }
    }
}

void display(){
    temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void count(){
    int count = 0;
    temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("%d", count);
}


void makeEmpty(){
    tail = head;
    head->data = 0;
    head->next = NULL;
    nw = head;
    n = 0;
}

void search(){
    int item, i, j, found;
    found = 0;
    printf("Enter the item u want to search for: ");
    scanf("%d", &item);
    temp = head;
    for (i = 0; i < n; i++){
        if (temp->data == item){
            found = 1;
            j = i + 1;
            break;
        }
        temp = temp->next;
    }
    if (found == 1){
        printf("Item found at node %d\n", j);
    }
    else{
        printf("Item not found\n");
    }
    
}


void merge() {
    int i;
    printf("To merge 2 linked lists first create the other list: \n");
    creation1();
    tail->next = head1;
    tail = tail1;
    tail1 = NULL;
    head1 = NULL;
    tail->next = NULL;
    n += n1;
}
