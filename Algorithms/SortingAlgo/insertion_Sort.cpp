#include <bits/stdc++.h> 
using namespace std; 
  
void insertionSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 1; i < n; i++) 
    {  
        int temp = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > temp) 
        {  
            arr[j + 1] = arr[j];  
            j--; 
        }  
        arr[j + 1] = key;  
    }  
}  
  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
int main()  
{  
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    insertionSort(arr, n);  
    printArray(arr, n);
    return 0;  
}  