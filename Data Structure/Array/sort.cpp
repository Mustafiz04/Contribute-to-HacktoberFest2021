#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int l,int h)
{
	int pivot=a[l];
	int i=l,j=h;
	do
	{
		do{i++;}while(a[i]<=pivot);
		do{j--;}while(a[j]>pivot);
		if(i<j)
		swap(&a[i],&a[j]);
	}while(i<j);
	swap(&a[l],&a[j]);
	return j;
}
void quicksort(int a[],int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}

void Merge(int a[],int l,int mid,int h)
{
	int i=l,j=mid+1,k=l;
	int b[100];
	while(i<=mid && j<=h )
	{
		if(a[i]<a[j])
		b[k++]=a[i++];
		else
		b[k++]=a[j++];
	}
	for(;i<=mid;i++)
	b[k++]=a[i];
	for(;j<=h;j++)
	b[k++]=a[j];
	for(i=l;i<=h;i++)
	a[i]=b[i];
}

void IMergeSort(int a[],int n)
{
	int i,p,l,h,mid;
	for(p=2;p<=n;p*=2)
	{
		for(i=0;i+p-1<n;i=i+p)
		{
			l=i;
			h=i+p-1;
			mid=(l+h)/2;
			Merge(a,l,mid,h);
		}
	}
	if(p/2<n)
	Merge(a,0,p/2,n-1);
}

void RMergeSort(int a[],int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)/2;
		RMergeSort(a,l,mid);
		RMergeSort(a,mid+1,h);
		Merge(a,l,mid,h);
	}
}
int count_digit(int n)
{
	int count=0;
	while(n>0)
	{
		count++;
		n/=10;
	}
	return count;
}
struct node
{
	int data;
	node *next;
};
void Insert(node** root,int key)
{
	node *t;
	t=new node;
	t->data=key;
	t->next=NULL;
	if(!*root)
	{
		*root=t;
	}
	else
	{
		node *p=*root;
		while(p->next)
		p=p->next;
		p->next=t;
	}
}
int del(node **root)
{
	if(!*root)
	return -1;
	else
	{
		node *t=*root;
		*root=t->next;
		int x=t->data;
		delete t;
		return x;
	}
}
void RadixSort(int a[],int n)
{
	node* *bins=new node*[10];
	int i,j,k,Max,div=1;
	for(i=0;i<10;i++)
	bins[i]=NULL;
	Max=*max_element(a,a+n);
	int cd=count_digit(Max);
	for(k=0;k<cd;k++)
	{
		for(i=0;i<n;i++)
		{
			Insert(&bins[(a[i]/div)%10],a[i]);
		}
		for(i=0,j=0;i<10;i++)
		{
			while(bins[i])
			{
				a[j++]=del(&bins[i]);
			}
		}
		div*=10;
		cout<<k+1<<"st parse :\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	}
}

void ShellSort(int a[],int n)
{
	int i,j,gap=n/2,temp;
	for(;gap>=1;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			temp=a[i];
			j=i-gap;
			while(j>=0 && a[j]>temp)
			{
				a[j+gap]=a[j];
				j=j-gap;
			}
			a[j+gap]=temp;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	ShellSort(a,n);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
