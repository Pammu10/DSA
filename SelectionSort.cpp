//Pramodh Krishna
//Selection Sort
#include<iostream>
using namespace std;

void selection_sort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j <= n - 1; j++){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {31, 41, 59, 26, 41, 58};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    selection_sort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    return 0;
}