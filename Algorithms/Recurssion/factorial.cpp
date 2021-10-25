//given an integer n to find factorial of that number cpp code
//factorial function
#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
	if(n==0 || n==1) return 1;
	else return(n*fact(n-1));
}
int main()
{
	int n;cin>>n;
	int ans=fact(n);
	cout<<"factorial of given number is "<<ans<<"\n";
	return 0;
}