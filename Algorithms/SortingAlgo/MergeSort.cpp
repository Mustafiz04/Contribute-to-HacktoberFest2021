#include <iostream>
using namespace std;

void merge(int arr[], int left, int right) {
    int mid = (left+right)/2;
    int pos = left;
    int l_size = mid - left + 1, r_size = right - mid;
    int l[l_size], r[r_size];
    for (int i=0; i<l_size; i++) 
        l[i] = arr[left+i];
    for (int i=0; i<r_size; i++)
        r[i] = arr[mid+i+1];

    int i=0, j=0;
    while (i<l_size && j<r_size) {
        if (l[i] <= r[j])
            arr[pos++] = l[i++];
        else    arr[pos++] = r[j++];
    }

    while (i<l_size)
        arr[pos++] = l[i++];
    while (j<r_size)
        arr[pos++] = r[j++];
}

void mergeSort(int a[], int left, int right) {
    if(left==right)
        return;
    int mid = (left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, right);
}

int main()
{
    int a[] = {10, 20, 5, 8, 7, 2, 15, 12};
    int n = 8;
    // Display the array 
    cout << "Initial array: "; 
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl; 
    /*
        Call function mergeSort on input array
        mergeSort(array, start, end)
    */
    mergeSort(a, 0, n-1);
 
    // Display the array 
    cout << "Sorted array: "; 
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl; 
    
    return 0;
}