#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

struct stack
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct stack* create(int capacity) 
{ 
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 


int isfull(struct stack **stack) 
{ 
    return (*stack)->top == (*stack)->capacity - 1; 
} 
  
int isempty(struct stack **stack) 
{ 
    return (*stack)->top == -1; 
} 
  
void push(struct stack **stack, int item) 
{ 
    if (isfull(&(*stack)))
    {
        return;
    }
    (*stack)->array[++(*stack)->top] = item; 
    printf("%d pushed to stack\n", item); 
} 

int pop(struct stack **stack) 
{ 
    if (isempty(&(*stack)))
    {
        return -144255114554;
    }
    return (*stack)->array[(*stack)->top--]; 
} 

int main() 
{ 
    struct stack* stack = create(100);
    int n;
    int i,x;
    printf("enter No. of  elements\n");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(&stack,x);
    }
    for(i=0;i<n;i++)
    {
        printf("%d popped from stack\n", pop(&stack)); 
    }
    return 0; 
} 