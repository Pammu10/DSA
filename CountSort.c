//Pramodh Krishna
//Count sort having time complexity O(n + k)

#include<stdio.h>  

int getMax(int a[], int n){
   int max  = a[0];
   for (int i = 1; i < n; i++){
      if (a[i] > max)
         max = a[i];
   }
   return max;
}

void count_sort(int a[], int n){
   int output[n+1];
   int max = getMax(a, n);
   int count[max+1];
   for (int i = 0; i <= max; i++){
      count[i] = 0;
   }
   for (int i = 0; i < n; i++){
      count[a[i]]++;
   }
   for (int i = 1; i <= max; i++){
      count[i] += count[i-1];
   }
   for (int i = n-1; i >= 0; i--){
      output[count[a[i]] - 1] = a[i];
   }
   for (int i = 0; i < n; i++){
      a[i] = output[i];
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
   count_sort(a, n);
   printf("\nArray after sorting: \n");
   for (int i = 0; i < n; i++){
      printf("%d ", a[i]);
   }
   return 0;
}
