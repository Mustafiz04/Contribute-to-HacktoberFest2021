#include <iostream>
using namespace std;
struct node
{
	int info;
	node* next;
};
class stacktype
{
	node* top;
	
public:
	stacktype()
	{
		top = NULL;
	}
	void push(node*);
	node* pop();
	bool isempty();
	void display();
	node* createnewnode(int);
};
node* stacktype:: createnewnode(int add)
{
	node* ptr;
	ptr = new node;
	ptr->info = add;
	ptr->next = NULL;
	return ptr;
}
void stacktype:: push(node* nptr)
{
	if (top == NULL)
		top = nptr;
	else
	{
		nptr->next = top;
		top = nptr;
	}
}
node* stacktype:: pop()
{
	node* temp;
	temp = top;
	top = top->next;
	return temp;
}
bool stacktype::isempty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}
void stacktype::display()
{
	if (isempty())
		cout << "\nCannot display.The stack is empty.";
	else
	{
		cout << "\nContents of the stack:  ";
		node* temp;
		for (temp = top;temp != NULL;temp = temp->next)
			cout << temp->info << "  ";
	}
}
int main()
{
	stacktype s;
	int add, del, e, f, choice;
	char ch = 'y';
	node* nptr;
	while (ch == 'y' || ch == 'Y')
	{
		cout << "Menu:";
		cout << "\n1.Push.";
		cout << "\n2.Pop.";
		cout << "\n3.Isempty?";
		cout << "\n4.Display.";
		cout << "\nEnter your choice(1-4):";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter an integer to be added:";
			cin >> add;
			nptr = s.createnewnode(add);
			s.push(nptr);
			s.display();
			break;
		case 2:
			e = s.isempty();
			if (e == 1)
				cout << "Cannot pop.Underflow.";
			else
			{
				nptr = s.pop();
				cout << nptr->info << " has been deleted.";
				delete nptr;
				s.display();
			}
			break;
		case 3:
			e = s.isempty();
			if (e == 1)
				cout << "Stack is empty.";
			else
				cout << "Stack is not empty.";
			break;
		case 4:
			s.display();
			break;
		default:
			cout << "Wrong input.Enter correct choice.";
		}
		cout << "\nDo you want to continue?(Y/N) ";
		cin >> ch;
	}
}

