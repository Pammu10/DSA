//Pramodh Krishna
//Merge Sort
#include<iostream>
using namespace std;


void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j;
    for (i = 0; i < n1; i++){
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = a[m + 1 + j];
    }
    i = j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
        }
    }
    while (i < n1){
        a[k++] = L[i++];
    }
    while (i < n2){
        a[k++] = R[j++];
    }

    
}
void merge_sort(int a[], int l, int r){
    if (l >= r){
        return;
    }
    else {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
        
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
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    return 0;
}