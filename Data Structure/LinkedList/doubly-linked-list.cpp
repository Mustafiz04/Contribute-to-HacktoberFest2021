using namespace std;
# include <bits/stdc++.h>
struct Node{
    int data;
    Node *Prev;
    Node *Next;
};
Node *head;
Node *tail;
struct Node* GetNode(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->Next = NULL;
    newNode->Prev = NULL;
    return newNode;
}
void InsertatHead(int x)
{
    Node *temp = GetNode(x);
    if(head==NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    head->Prev = temp;
    temp->Next = head;
    head = temp;
}
void PrintfromHead()
{
    cout << "The actual linked list is :\n";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<", ";
        temp = temp->Next;
    }
    cout << "\n";
}
void PrintfromTail()
{
    cout << "The reversed linked list is :\n";
    Node *temp = tail;
    while(temp!=NULL)
    {
        cout << temp->data << ", ";
        temp = temp->Prev;
    }
    cout << "\n";
}
void InsertatTail(int x)
{
    Node *temp = GetNode(x);
    if(tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->Prev = tail;
    tail->Next = temp;
    tail = temp;
}
int main()
{
    char ch,ch1;
    int n,x;
    do
    {
        cout << "Enter your choice A. Insert a node at tail B. Insert a node at head. ";
        cin >> ch;
        switch (ch)
        {
        case 'A':
            cout << "Enter Number :";
            cin >> x;
            InsertatTail(x);
            break;
        case 'B':
            cout << "Enter Number :";
            cin >> x;
            InsertatHead(x);
            break;
        default:
            cout << "Invalid Input. Try again";
            break;
        }
        cout << "Enter 'Y' to continue. Enter 'N' to exit.";
        cin >> ch1;
    } while (ch1 == 'Y');
    PrintfromHead();
    PrintfromTail();
}