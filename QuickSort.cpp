//Pramodh Krishna
//Quick Sort
#include<iostream>
using namespace std;


int split(int a[], int lower, int upper){
    int temp;
    int pivot = a[lower];
    int newlower = lower;
    int newupper = upper;
    while (newlower < newupper){
        while (a[newlower] <= pivot) 
            newlower++;
        while (a[newupper] > pivot)
            newupper--;
        if (newlower < newupper){
            temp = a[newlower];
            a[newlower] = a[newupper];
            a[newupper] = temp;
        }
    }
    a[lower] = a[newupper];
    a[newupper] = pivot;
    return newupper;
}
void quick_sort(int a[], int lower, int upper){
    if (lower < upper){
        int i = split(a, lower, upper);
        quick_sort(a, lower, i -1);
        quick_sort(a, i + 1, upper); 
    }   
}

int main()
{
    int arr[] = {45, 19, 11, 62, 40, 80, 9, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    return 0;
}