#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *s,char value){
    if(isFull(s)){
        printf("\nStack Overflow! %d cannot be entered in stack\n",value);
    }
    else{
        s->top++; //increment the top and..
        s->arr[s->top] = value; 
    }
}

char pop(struct stack *s){
    if(isEmpty(s)){
        printf("\nStack Underflow!\n");
        return -1;
    }
    else{
        char value = s->arr[s->top]; 
        s->top--; 
        return value;
    }
}

int match(char a, char b){
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int parathesisCheck(char * exp){

    //-Initialized the stack
    struct stack *s;
    s->size = 100;
    s->top= -1;
    s->arr = (char *) malloc (s->size * sizeof(char));
    char poppedElement;

    for (int i = 0; i < exp[i]!='\0'; i++) //till null character
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(s)){
                return 0; //false
            }
            poppedElement = pop(s); 
            if(!match(poppedElement,exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main()
{

    char * exp = " (a+b) [c+d] ";

    if(parathesisCheck(exp)){
        printf("Parenthesis is matching : Balanced \n");
    }
    else{
        printf("Parenthesis is not matching : Not Balanced \n");
    }
    
    return 0;
}
