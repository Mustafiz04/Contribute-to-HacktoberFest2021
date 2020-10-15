#include<iostream>
using namespace std;
template <class T>
class queue
{
	int size;
	int front;
	int rear;
	T *a;
	
	public:
		queue(int size)
		{
			this->size=size;
			front=rear=-1;
			a=new T[this->size];
		}
		void enqueue();
		T dequeue();
		void display();
};
template <class T>
void queue<T>::enqueue()
{
	if(this->rear==this->size-1)
	{
		cout<<"Queue is full.";
		return;
	}
	this->rear++;
	cout<<"Enter the element:";
	cin>>this->a[this->rear];
}
template <class T>
T queue<T>::dequeue()
{
	if(this->front==this->rear)
	{
		cout<<"Queue is empty."<<endl;
	}
	else
	{
		this->front++;
		return this->a[this->front];
	}
}
template <class T>
void queue<T>::display()
{
	cout<<"Elements of queue:"<<endl;
	for(int i=this->front+1;i<=this->rear;i++)
	{
		cout<<this->a[i]<<endl;
	}
}
int main()
{
	queue<int> Q(10);
	int t=5;
	while(t--)
	Q.enqueue();
	Q.display();
	cout<<"Deleted element:"<<Q.dequeue()<<endl;
	Q.display();
}
