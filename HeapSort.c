//Pramodh Krishna
//Heap sort having time complexity O(nlogn)

#include<stdio.h>  

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) {
      int temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, i, 0);
    }
  }

int main()
{
   int n;
   printf("Enter the number of elemnets in your array: ");
   scanf("%d", &n);
   int a[n];
   for (int i = 0; i < n; i++){
      scanf("%d", &a[i]);
   }
   printf("Array before sorting: \n");
   for (int i = 0; i < n; i++){
      printf("%d ", a[i]);
   }
   heapSort(a, n);
   printf("\nArray after sorting: \n");
   for (int i = 0; i < n; i++){
      printf("%d ", a[i]);
   }
   return 0;
}
