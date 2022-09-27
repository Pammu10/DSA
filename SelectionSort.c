//Pramodh Krishna
//Selection sort having time complexity O(n^2)

#include<stdio.h>

void selection_sort(int arr[], int n){
	int i, j, k;
	for (i = 0; i < n - 1; i++){
		for (j = i + 1; j < n; j++){
			if (arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
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
	selection_sort(arr, n);
	printf("\nArray after sorting\n");
	for (int i = 0; i< n; i++){
		printf("%d ", arr[i]);
	}
	return 0;

}	
