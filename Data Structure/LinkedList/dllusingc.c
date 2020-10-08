#include<stdio.h>
#include<stdlib.h>

struct node { 
    int data; 
    struct node *next; // Pointer to next node 
    struct node *prev; // Pointer to previous node 
};

void insertatfront(struct node **head, int x) 
{ 
    struct node *newnode = (struct node*)malloc(sizeof(struct node)); 
    newnode->data = x; 
    newnode->next = (*head); 
    newnode->prev = NULL; 
    if (*head != NULL)
    {
        (*head)->prev = newnode;
    }
    *head = newnode; 
}
void insertafter(struct node **prev, int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = (*prev)->next;
    (*prev)->next = newnode;
    newnode->prev = *prev;
    if (newnode->next != NULL)
    {
        newnode->next->prev = newnode;
    }
}
void append(struct node **head, int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    struct node *temp;
    temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void insertbefore(struct node **next,int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = (*next)->prev;
    (*next)->prev = newnode;
    newnode->next = *next;
    if (newnode->prev != NULL)
    {
        newnode->prev->next = newnode;
    }
}
void deleteNode(struct node** head_ref, struct node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}
void printforward(struct node **head)  
{  
    struct node *temp;
    temp = *head;
    printf("\nTraversal in forward direction \n");  
    while (temp != NULL) 
    {  
        printf(" %d ", temp->data);
        temp = temp->next;  
    }
    printf("\n");
}
void printbackward(struct node **head)
{
    struct node *last,*node;
    node = *head; 
    printf("\nTraversal in reverse direction \n");
    while (node != NULL) 
    {
        last = node;  
        node = node->next;  
    }
    while (last != NULL) 
    {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }
    printf("\n");
}  
  
int main()
{
    struct node *head,*temp;
    int n,x,i,l;
    printf("Enter no of elements: \n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("empty list");
    }
    else
    {
        printf("Enter elements: \n");
        scanf("%d",&x);
        head->data = x;
        head->next = NULL;
        head->prev = NULL;
        for(i=2;i<=n;i++)
        {
            scanf("%d",&x);
            append(&head,x);//basically insertion at end operation
        }
        printforward(&head);
        printbackward(&head);
        printf("Enter no of elements to be inserted at front\n");
        scanf("%d",&l);
        int pos;
        for(i=0;i<l;i++)
        {
            printf("Enter elements \n");
            scanf("%d",&x);
            insertatfront(&head,x);
        }
        printforward(&head);
        printf("enter no of elements to be inserted before a node \n");
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
            printf("Enter Position \n");
            scanf("%d",&pos);
            printf("enter element \n");
            scanf("%d",&x);
            while(pos)
            {
                temp = temp->next;
                pos--;
            }
            insertbefore(&temp,x);
        }
        printforward(&head);
        printf("enter no of elements to be inserted after a node \n");
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
            printf("Enter Position \n");
            scanf("%d",&pos);
            printf("enter element \n");
            scanf("%d",&x);
            while(pos)
            {
                temp = temp->next;
                pos--;
            }
            insertafter(&temp,x);
        }
        printf("enter no of elements to delete \n");
        scanf("%d",&l);
        for(i=0;i<l;i++)
        {
	    printf("enter position \n");
	    scanf("%d",&pos);
            struct node* current = head; 
            int k;
            for (int k = 1; current != NULL && k < pos; k++)
            {
                current = current->next;
            }
            if (current == NULL)
            {
                printf("Can't delete");
            }
            deleteNode(&head, current);
        }
    }
    return 0;
}
 
