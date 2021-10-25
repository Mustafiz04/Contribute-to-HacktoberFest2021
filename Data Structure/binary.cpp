#include <bits/stdc++.h> 
using namespace std; 
int BinarySearch(int a[], int start, int end, int x) 
{ 
    if (end >= start) { 
        int mid = start + (end - start) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (a[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (a[mid] > x) 
            return BinarySearch(a, start, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return BinarySearch(a, mid + 1, end, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
  
int main() 
{ 
    int arr[] = { 2, 3, 4, 10, 40 },x; 
    cout<<"ENter a number for search";
	cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]); 
    int flag = BinarySearch(arr, 0, n - 1, x); 
    (flag == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << flag; 
    return 0; 
} 
