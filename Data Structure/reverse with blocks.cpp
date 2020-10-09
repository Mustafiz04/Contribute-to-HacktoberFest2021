#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int a[] = {0,1,2,3,4,5,6,7};
	int x=4,start=0, end=4;
	int len =sizeof(a)/sizeof(int);
	do
	{
	    for(int i=start;i<end/2;i++)
	    {
		    swap(&a[i],&a[x-i-1]);
	    }
	    len=len-x;
	    start=start+x;
	    end=end+x;
    }while(len>=0);
	cout<<"The reversed array \n";
	int len2=sizeof(a)/sizeof(int);
	for(int i=0;i<len2;i++)
	{
		cout<<a[i]<<" ";
	}	
} 
