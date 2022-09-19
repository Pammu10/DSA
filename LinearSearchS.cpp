//Pramodh Krishna
//Linear Search for sorted array
#include<iostream>
using namespace std;

void linear_search(int a[], int n, int k)  
{    
    bool present = false;
    if (k < a[0] || k > a[n-1]){
        present = false;
    }
    else {
        for (int i = 0; (i < n) && (present == false); i++){
        if (a[i] == k){
            present = true;
            cout << k << " found at position " << i+1 << endl;
        }  
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
    linear_search(arr, n, k);
    return 0;
}