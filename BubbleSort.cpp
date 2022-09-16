//Pramodh Krishna
//Bubble sort
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j + 1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main(){
    int arr[] = {31, 41, 59, 26, 41, 58};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i< n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    bubble_sort(arr, n);
    for (int i = 0; i< n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}