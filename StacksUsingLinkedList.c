//Pramodh Krishna
//Stacks using Linked

#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* next;
}*nw, *top, *temp, *temp1;


void push(int);
void pop();
void display();

int main()
{
    nw = (struct node*) malloc(sizeof(struct node));
    top = nw;
    nw->data = 0;
    top->next = NULL;
    int l = 1;
    int choice;
    

    while (l == 1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter ur choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int item;
            printf("Enter the item u want to push");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
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


void push(int item){
    nw = (struct node*) malloc(sizeof(struct node));
    nw->next = top;
    top = nw;
    top -> data = item;
    }


void pop(){
    temp = top;
    temp1 = top;
    if (top->data != 0){
        top = temp->next;
        temp->next = NULL;
        printf("%d", temp1->data);
        free(temp);
    }
    else {
        printf("Stack underflow");
    }
}

void display(){
    temp = top;
    while(temp->data != 0){
        printf("%d\t", temp->data);
        temp = temp->next;
        
    }
}
