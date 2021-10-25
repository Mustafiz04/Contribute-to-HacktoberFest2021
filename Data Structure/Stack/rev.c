#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
struct stack
{ 
    int top; 
    unsigned capacity; 
    char* array; 
}; 

struct stack* create(int capacity) 
{ 
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (char*)malloc(stack->capacity * sizeof(char)); 
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
  
void push(struct stack **stack, char item) 
{ 
    if (isfull(&(*stack)))
    {
        return;
    }
    (*stack)->array[++(*stack)->top] = item; 
    printf("%c pushed to stack\n", item); 
} 

char pop(struct stack **stack) 
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
    char n[100];
    int i,x;
    printf("enter string\n");
    scanf("%s",n);
    x = strlen(n);
    for(i=0;i<x;i++)
    {
        push(&stack,n[i]);
    }
    printf("Reverse:\n");
    for(i=0;i<x;i++)
    {
        printf("%c", pop(&stack)); 
    }
    printf("\n");
    return 0; 
} 
