
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

struct StackNode { 
	int data; 
	struct StackNode* next; 
}; 

struct StackNode* newnode(int data) 
{ 
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
	stackNode->data = data; 
	stackNode->next = NULL; 
	return stackNode; 
} 

int isEmpty(struct StackNode **head) 
{ 
	return !(*head); 
} 

void push(struct StackNode **root, int data) 
{ 
	struct StackNode* stackNode = newnode(data); 
	stackNode->next = *root; 
	*root = stackNode; 
	printf("%d pushed to stack\n", data); 
} 

int pop(struct StackNode **head) 
{ 
	if (isEmpty(&(*head))) 
		return -101154454155; 
	struct StackNode* temp = *head; 
	*head = (*head)->next; 
	int popped = temp->data; 
	free(temp); 

	return popped; 
} 

int main() 
{ 
	struct StackNode* head = NULL; 
	int i,n,x;
	printf("Enter no of elements \n");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&x);
	    push(&head,x);
	}
	for(i=0;i<n;i++)
	{
	    printf("%d popped from stack\n", pop(&head));
	}
	return 0; 
} 
