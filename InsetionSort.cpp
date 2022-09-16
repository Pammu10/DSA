//Pramodh 
//Insertion Sort having time complexity 0(n^2)
#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        for (int j = 0; j < i; j++){
            if (arr[i] < arr[j]){
                int k;
                for ( k= i; k > j; k--){
                    arr[k] = arr[k - 1];
                }
                arr[k] = temp;  
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
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    return 0;
}
