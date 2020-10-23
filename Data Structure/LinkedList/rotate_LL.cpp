#include <bits/stdc++.h>
using namespace std;
struct LLNode{
  int data;
  LLNode *next;  
};
//This funnction will rotate the list counter clockwise by k nodes
void rotate(LLNode** head, int k)
{
  LLNode* temp = *head;
  int count = 1;
  if (k==0)
  {
    return ;
  }
  //Pointing temp to the kth node
  while(count<k && temp != NULL) {
      temp = temp->next;
      count++;
  }
  //If it is NULL then dont rotate
  if (temp==NULL)
  {
    return;
  }
  //point KthNode to temp
  LLNode* KthNode = temp;
  //Move temp to the last node
  while(temp->next != NULL) {
      temp = temp->next;
  }
  //point next of temp to the head
  temp->next = *head;
  //change head to the next of Kth node
  *head = KthNode->next;
  //Point next of KthNode to NULL
  KthNode->next = NULL;
}
void insertAtBeginning(LLNode**head,int dataToBeInserted)
{
  LLNode*curr=new LLNode;
  //make a new node with this data and next pointing to NULL
  curr->data=dataToBeInserted;
  curr->next=NULL;
  if(*head==NULL) //if list is empty then set the current formed node as head of list
      *head=curr;
    
  else //make the next of the current node point to the present head and make the current node as the new head
    {
      curr->next=*head;
      *head=curr;
    }
    
    //O(1) constant time
}
void display(LLNode**head)
{
  LLNode*temp=*head;
  while(temp!=NULL) //till the list ends (NULL marks ending of list)
    {
      if(temp->next!=NULL)
      cout<<temp->data<<" ->";
      else
      cout<<temp->data;
      
      temp=temp->next; //move to next node
    }
    //O(number of nodes)
  cout<<endl;
}
int main() 
{    
  
  LLNode *head = NULL; //initial list has no elements
  int k = 4;
  insertAtBeginning(&head,6);
  insertAtBeginning(&head,16);
  insertAtBeginning(&head,15);
  insertAtBeginning(&head,50);
  insertAtBeginning(&head,1);
  insertAtBeginning(&head,23);
  
  cout<<"\nCurrent List is :-\n";
  display(&head);
  rotate(&head, k);
  cout<<"After rotating the linked list counter clockwise by k nodes"<<endl;
  display(&head);
  return 0;
}
