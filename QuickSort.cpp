//Pramodh Krishna
//Quick Sort having time complexity O(nlogn)

#include<stdio.h>

int split(int arr[], int lower, int upper){
    int pivot = arr[lower];
    int newlower = lower;
    int newupper =upper;
    while (newlower < newupper){
        while(arr[newlower] <= pivot)
            newlower++;
        
        while (arr[newupper] > pivot)
            newupper--;

        if (newlower < newupper){
            int temp = arr[newlower];
            arr[newlower] = arr[newupper];
            arr[newupper] = temp;
        }
    }
    arr[lower] = arr[newupper];
    arr[newupper] = pivot;
    return newupper;
}

void quick_sort(int arr[], int lower, int upper){
    if (lower < upper){
        int i = split(arr, lower, upper);
        quick_sort(arr, lower, i - 1);
        quick_sort(arr, i + 1, upper);   
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
    quick_sort(arr, 0, n-1);
    printf("\nArray after sorting\n");
    for (int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
