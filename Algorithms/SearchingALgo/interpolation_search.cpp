//Algoritm-----------------------------------------------
// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]
//pos = lo + [ (x - arr[lo]) * (hi - lo) / (arr[hi] - arr[Lo]) ]
/*
arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]


Let's assume that the elements of the array are linearly distributed.

General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of lo,hi and x in the equation
arr[hi] = m*hi+c ----(1)
arr[lo] = m*lo+c ----(2)
x = m*pos + c     ----(3)

m = (arr[hi] - arr[lo] )/ (hi - lo)

subtracting eqxn (2) from (3)
x - arr[lo] = m * (pos - lo)
lo + (x - arr[lo])/m = pos
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo])


*/

// C++ program to implement interpolation
// search with recursion
#include <bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
	int pos;

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {

		// Probing the position with keeping
		// uniform distribution in mind.
		pos = lo
		      + (((double)(hi - lo) / (arr[hi] - arr[lo]))
		         * (x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in right sub array
		if (arr[pos] < x)
			return interpolationSearch(arr, pos + 1, hi, x);

		// If x is smaller, x is in left sub array
		if (arr[pos] > x)
			return interpolationSearch(arr, lo, pos - 1, x);
	}
	return -1;
}

// Driver Code
int main()
{

	// Array of items on which search will
	// be conducted.
	int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21,
	              22, 23, 24, 33, 35, 42, 47
	            };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Element to be searched
	int x = 18;
	int index = interpolationSearch(arr, 0, n - 1, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";

	return 0;
}

// This code is contributed by equbalzeeshan
