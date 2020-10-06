#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* next;
};Node* head;
void insert(int data,int n)
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if(n==1)
	{
		temp1->next = head;
		head= temp1;
		return;
	}
	Node* temp2 = head;
	for(int i = 0;i<n-2;i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void insertend(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	Node* temp2 = head;
	while( temp2->next!= NULL)
	{
		temp2 = temp2->next;
	}temp2->next = temp;
}
void Print()
{
	cout<<"The resulting list is : ";
	Node* temp = head;
	while(temp !=  NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
void Delete(int n)
{
	Node* temp = head;
	if(n == 1)
	{
		head = temp->next;
		delete temp;
		return;
	}
	for(int i = 0;i<n-2;i++)
	{
		temp = temp->next;
	}
	Node* temp2 = new Node;
	temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
}
int main()
{
	int data,n;
/*	cout<<"Enter the data and the position separated by space.";
	cout<<endl<<"And then press enter to see the result.";
	cout<<endl;
	while(n>0)
	{
		cin>>data;
		cin>>n;
		insert(data,n);
		Print();
		cout<<endl;
	}*/
	insert(3,1);//3
	insert(2,1);//2 3
	insert(6,3);//2 3 6
	insert(4,2);//2 4 3 6
	insertend(15);//2 4 3 6 15 
	insertend(19);//2 4 3 6 15 19
	insert(20,6);//2 4 3 6 15 20 19
	Print();
	cout<<endl;
	Delete(3);//3 is the position of the node we wanna delete;
	cout<<"After deletion : ";
	Print();
}
