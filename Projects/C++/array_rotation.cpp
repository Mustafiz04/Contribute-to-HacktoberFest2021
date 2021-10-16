//C++ program for right rotation of array using juggling algorithm
#include <iostream>
using namespace std;

int gcd(int n,int k) {
	if(k == 0)
	return n;

	return gcd(k,n%k);
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n,k;
		cin>>n>>k;
		int* arr = new int[n];

		for(int i=0; i<n; ++i) {
			cin>>arr[i];
		}

		k = k % n;
		int sets = gcd(n,k);

		for(int i=0; i<sets; ++i) {
			int j = i, curr = arr[j];
			while(true) {
				int nextInd = (j+k)%n;
				if(nextInd == i)
				break;

				int temp = arr[nextInd];
				arr[nextInd] = curr;
				curr = temp;
				j = nextInd;
			}
			arr[i] = curr;
		}

		for(int i=0; i<n; ++i) {
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}