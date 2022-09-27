//Pramodh Krishna
//Shell Sort having time complexity 0(n^2)

#include<stdio.h>  

void shell_sort(int arr[], int n){
    int i, k;
    for (k = n/2; k > 0; k/= 2){
		for (int i = k; i < n; i++){
			int temp = arr[i];
			int j;
			for (j = i; j>= k && arr[j-k] > temp; j-=k){
				arr[j] = arr[j - k];
			}
			arr[j] = temp;
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
   shell_sort(arr, n);
   printf("\nArray after sorting\n");
   for (int i = 0; i< n; i++){
      printf("%d ", arr[i]);
   }
    return 0;
   
}
