//Pramodh Krishna
//Merge Sort having time complexity O(nlogn)

#include<stdio.h>

void merge(int arr[], int lower, int mid, int upper){
    int n1 = mid - lower + 1;
    int n2 = upper - mid;
    int L[n1], R[n2];
    int i, j;
    for (i = 0; i < n1; i++){
        L[i] = arr[lower + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    i = j = 0;
    int k = lower;
    while(i < n1 && j < n2){
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2){
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int lower, int upper){
    if (lower < upper){
        int mid = (lower + upper) / 2;
        merge_sort(arr, lower, mid);
        merge_sort(arr, mid + 1, upper);
        merge(arr, lower, mid, upper);   
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
    merge_sort(arr, 0, n-1);
    printf("\nArray after sorting\n");
    for (int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
