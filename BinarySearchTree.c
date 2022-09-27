//Pramod Krishna
//Binary search tree

#include<stdio.h>  
#include <malloc.h>

struct node {  
	int data;  
	struct node *left, *right;  
}; 

struct node* create(int item){
   struct node *nw = (struct node*)malloc(sizeof(struct node));
   nw->left = NULL;
   nw->right = NULL;
   nw->data = item;
   return nw;
}

struct node* insert(struct node* tree, int x){
   if (tree == NULL)
      return create(x);
   if(x < tree->data)
      tree->left = insert(tree->left, x);
   else if(x > tree->data)
      tree->right = insert(tree->right, x);
   
   return tree;
}

struct node* creation(){
	int n, item;
	struct node* root = NULL;
	printf("Enter how many nodes you want to create: ");
	scanf("%d", &n);
   printf("Enter the value: ");
   scanf("%d", &item);
   root = insert(root, item);
	for (int i = 1; i < n; i++){
    	printf("Enter the value: ");
    	scanf("%d", &item);
    	insert(root, item);
	}
	return root;
}

void inorder(struct node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void preorder(struct node* root){
   if (root != NULL){
      printf("%d ", root->data);
      preorder(root->left);
      preorder(root->right);
   }
}

void postorder(struct node* root){
   if (root != NULL){
      preorder(root->left);
      preorder(root->right);
      printf("%d ", root->data);
   }
}

struct node* successor(struct node* root){
   struct node* temp = root;
   while(temp != NULL && temp->left != NULL){
      temp = temp->left;
   }
   return temp;
}

struct node* delete(struct node* root, int x){
   if (root == NULL){
      return root;
   }
   if (x < root->data)
      root->left = delete(root->left, x);
   else if(x > root->data)
      root->right = delete(root->right, x);
   
   else {
      if (root->left == NULL){
         struct node* temp = root->right;
         free(root);
         return temp;
      }
      else if(root->right == NULL){
         struct node* temp = root->left;
         free(root);
         return temp;
      }
      struct node* temp = successor(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
   }  
   return root; 
}



int main(){
   int l, choice, item;
   l = 0;
   while (l == 0){
      printf("1.Create\n2.Insert\n3.delete\n4.inorder\n5.preorder\n6.postorder\n7.exit");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         struct node* lw = creation();
         break;
      case 2:
         printf("Enter the item you want to insert");
         scanf("%d", &item);
         insert(lw, item);
         break;
      case 3:
         printf("Enter the item you want to delete");
         scanf("%d", &item);
         delete(lw, item);
         break;
      case 4:
         inorder(lw);
	 printf("\n");
         break;
      case 5:
         preorder(lw);
         printf("\n");
         break;
      case 6:
         postorder(lw);
         printf("\n");
         break;
      case 7:
         l = 1;
         break;
      
      default:
         printf("Enter a number between 1 and 7");
         break;
      }
   }
   return 0;
   
}
