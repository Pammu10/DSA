#include<stdio.h>
#include<malloc.h>

struct node {
    int power;
    int coeff;
    struct node* next;
};
struct node *nw, *head1, *head2, *head3, *tail1, *tail2, *tail3, *temp, *temp1, *temp2;


void creation1(int);
void creation2(int);
void creation3(int);
void insertion1(int, int);
void insertion2(int, int);
void display1();
void display2();
void display3(int);
void add(int);


int main(){
    int n1, n2, i, c;
    printf("Enter the highest degree of polynomial of equations: ");
    scanf("%d", &n1);
    creation1(n1);
    for (i = n1 ; i >= 0; i--){
        printf("Enter the coeff of power %d of x", i);
        scanf("%d", &c);
        insertion1(c, i);
    }
    creation2(n1);
    for (i = n1 ; i >= 0; i--){
        printf("Enter the coeff of power %d of x", i);
        scanf("%d", &c);
        insertion2(c, i);
    }
    display1();
    display2();
    add(n1);
    display3(n1);
    return 0;
}

void creation1(int n){
    nw = (struct node*) malloc(sizeof(struct node));
    head1 = nw;
    tail1 = nw;
    tail1->next = NULL;
    nw->power = 0; 
    nw->coeff = 0;
    for (int i = 1; i < n + 1; i++){
        nw = (struct node*) malloc(sizeof(struct node));
        nw->power = i;
        nw->coeff = 0;
        tail1->next = nw;
        nw->next = NULL;
        tail1 = nw;
    }
    
}

void insertion1(int co, int pow){
    temp = head1;
    for (int i = 0; i < pow; i++){
        temp = temp->next;
    }
    temp->coeff = co;
}

void display1(){
    temp = head1;
    while(temp != NULL){
        printf("%d\t", temp->coeff);
        printf("%d\n", temp->power);
        temp = temp->next;
    }
}

void creation2(int n){
    nw = (struct node*) malloc(sizeof(struct node));
    head2 = nw;
    tail2 = nw;
    tail2->next = NULL;
    nw->power = 0; 
    nw->coeff = 0;
    for (int i = 1; i < n + 1; i++){
        nw = (struct node*) malloc(sizeof(struct node));
        nw->power = i;
        nw->coeff = 0;
        tail2->next = nw;
        nw->next = NULL;
        tail2 = nw;
    }
    
}

void insertion2(int co, int pow){
    temp = head2;
    for (int i = 0; i < pow; i++){
        temp = temp->next;
    }
    temp->coeff = co;
}

void display2(){
    temp = head2;
    while(temp != NULL){
        printf("%d\t", temp->coeff);
        printf("%d\n", temp->power);
        temp = temp->next;
    }
}

void creation3(int n){
    nw = (struct node*) malloc(sizeof(struct node));
    head3 = nw;
    tail3 = nw;
    tail3->next = NULL;
    nw->power = 0; 
    nw->coeff = 0;
    for (int i = 1; i < n + 1; i++){
        nw = (struct node*) malloc(sizeof(struct node));
        nw->power = i;
        nw->coeff = 0;
        tail3->next = nw;
        nw->next = NULL;
        tail3 = nw;
    }
    
}

void add(int x){
    temp1 = head1;
    temp2 = head2;
    creation3(x);
    temp = head3;
    for (int i = 0; i < x+1; i++){
        temp->coeff = temp1->coeff + temp2->coeff;
        temp = temp->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
        }
}

void display3(int n){
    for (int i = n; i >= 0; i--){
        temp = head3;
        for (int j = 0; j < i; j++){
            temp = temp->next;
            }
    printf("%dx^%d\t", temp->coeff, i);
    }
}