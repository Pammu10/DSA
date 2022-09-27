//Pramodh Krishna
//Bubble sort having time complexity O(n^2)

#include<stdio.h>  

void bubble_sort(int arr[], int n){
   int i, j;
   for (i = 0; i < n; i++){
      for (j = 0; j < n - 1 - i; j++){
         if (arr[j] > arr[j + 1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

int main(){
   int n, item;
   printf("Enter number of elements in your array: ");
   scanf("%d", &n);
   int arr[n];
   for (int i = 0; i < n; i++){
      scanf("%d", &arr[i]);
   }
   printf("Array before sorting\n");
   for (int i = 0; i < n; i++){
      printf("%d ", arr[i]);
   }
   bubble_sort(arr, n);
   printf("\nArray after sorting\n");
   for (int i = 0; i< n; i++){
      printf("%d ", arr[i]);
   }
   return 0;
   
}
