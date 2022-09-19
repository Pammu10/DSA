//Pramodh Krishna
//Binary Search
#include<iostream>
using namespace std;

void binary_search(int a[], int n, int k)  
{    
    bool present = false;
    int low = 0;
    int high = n-1;
    int mid; 
    while (low <= high){
        mid = (low + high) / 2;
        if (a[mid] == k){
        present = true;
        cout << k << " found at position " << mid+1 << endl;
        break;
        } 
        else if(a[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }    
    }
    
    if (present == false)
        cout << "Not found" << endl;
    
}   

int main()
{
    int arr[] = {26, 31, 41, 41, 58, 59};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    printf("Enter the number you want to find: ");
    scanf("%d", &k);
    binary_search(arr, n, k);
    return 0;
}