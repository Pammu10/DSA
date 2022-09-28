//Pramodh Krishna
//Linear search for sorted array having time complexity O(n)

#include<stdio.h>

int linear_search(int arr[], int n, int item){
    int found = 0;
    if (item > arr[n-1] || item < arr[0])
        found = 0;
    else {
        for (int i = 0; i < n; i++){
        if (arr[i] == item){
            found = 1;
            printf("Item found at position %d", i + 1);
            break;
        }
    }
}
    if (found == 0)
        printf("Item not found in the array");
}

int main(){
    int n, item;
    printf("Enter number of elements in your array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the item you want to search for in the array: ");
    scanf("%d", &item);
    linear_search(arr, n, item);
    return 0;
}
