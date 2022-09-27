//Pramodh Krishna
//Insertion Sort having time complexity 0(n^2)

#include<stdio.h>  

void insertion_sort(int arr[], int n){
   int i, j, k;
   for (i = 1; i < n; i++){
      int temp = arr[i];
      for (j = 0; j < i; j++){
         while (temp < arr[j]){
            int k;
            for (k = i; k > j; k--){
               arr[k] = arr[k - 1];
            }
            arr[k] = temp;
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
   insertion_sort(arr, n);
   printf("\nArray after sorting\n");
   for (int i = 0; i< n; i++){
      printf("%d ", arr[i]);
   }
   return 0;
   
}
