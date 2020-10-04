#include <iostream>
#include <stdio.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head;
void Print();
void Insert(int data,int n)
{
    cout << "Inserting at the given position \n";
    Node *temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(n==1)
    {
        temp1->next = head;
        head = temp1;
        Print();
        return;
    }
    Node *temp2 = head;
    for (int i = 0; i < n - 2;i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    Print();
}
void Reverse()
{
    cout << "Reversing \n";
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    Print();
}
void InsertEnd(int data)
{
    cout << "Inserting at Tail \n";
    Node *temp = new Node;
    temp->data = data;
    Node* temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->next = NULL;
    Print();
}
void InsertFirst(int data)
{
    cout << "Inserting at head \n";
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    Print();
}
void DeleteEnd()
{
    cout << "Deleting from tail \n";
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
    
    Print();
}
void DeleteFirst()
{
    cout << "Deleting from head \n";
    Node *temp = head;
    head = temp->next;
    delete (temp);
    Print();
}
void Print()
{
    cout << "The resulting list is : "
        << "\n";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    Insert(3, 1);
    Insert(2, 2);
    Insert(1, 1);
    InsertEnd(13);
    InsertEnd(12);
    InsertFirst(98);
    DeleteEnd();
    DeleteFirst();
    InsertEnd(243);
    InsertFirst(128);
    Reverse();
}