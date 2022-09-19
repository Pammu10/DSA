//Pramodh Krishna
//Shell Sort
#include<iostream>
using namespace std;

void shell_sort(int a[], int n)  
{    
    for (int k = n/2; k > 0; k /= 2)  
    {  
        for (int i = k; i < n; i += 1)  
        {    
            int temp = a[i];  
            int j;        
            for (j = i; j >= k && a[j - k] > temp; j -= k)  
                a[j] = a[j - k];  
              
            a[j] = temp;  
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
    shell_sort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << "\t";
    }
    return 0;
}