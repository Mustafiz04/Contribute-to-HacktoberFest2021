Program to implement linear search algorithm in C++

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,n,key;
    
    cout<<"Enter the size of the array: ";
    cin>>n;
    int *arr = new int(n);  
    
    cout<<"Enter the array elements: ";
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    cout<<"Enter the key to be searched: ";
    cin>>key;
    
    for(i=0;i<n;i++)    //Searching element using linear search.
    {
      if(key==arr[i])
      {
        cout<<"The key element is found at index : "<<i+1;
        break;
      }
    }
    if(i==n)
    cout<<"Element not found";
}


Time Complexity
For Linear Search
Best
O(1)

Average
n(n+1)/2n = O(n)

Worst
O(n)

Space Complexity
O(1)
A space complexity of O(1) means that the space required by the algorithm to process data is constant; 
it does not grow with the size of the data on which the algorithm is operating.

Average Comparisions
(N+1)/2
