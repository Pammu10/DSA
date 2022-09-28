//Pramodh Krishna
//Binary search for sorted array having time complexity O(logn)

#include<stdio.h>

int binary_search(int arr[],int upper, int item){
    int lower = 0;
    int found = 0;
    
    while (lower <= upper){
        int mid = (lower + upper) / 2;
        if (arr[mid] == item){
            found = 1;
            printf("Item found at position %d", mid + 1);
            break;
        }
        else if (arr[mid] > item){
            upper = mid - 1;
        }
        else if (arr[mid] < item){
            lower = mid + 1;
        }
    }
    if (found == 0){
        printf("Item not found");
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
    printf("Enter the item you want to search for in the array: ");
    scanf("%d", &item);
    binary_search(arr, n, item);
    return 0;
}
