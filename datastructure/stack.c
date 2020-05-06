/*-------------------------------------------------------- Stack -----
 |  Author: Tarek Alakmeh
 |  Date:   Mai 2020
 |  Lang:   C (English)
 |  Note:   A stack is an abstract data type. Usually it would not be
 |            possible to print the entire stack without popping all
 |            its values. However, the stack has been implemented in C
 |            using an underlying array of size n, which the function 
 |            printStack iterates over to print the stack without
 |            popping the values.
 |
 |    struct
 |      - stack
 |
 |    functions
 |      - initStack
 |      - push
 |      - pop
 |      - printStack
 |      - main (example)
 |
 *-------------------------------------------------------------------*/
 
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int* arr;
    int size;
    int top;
};


/*---------------------------------------------------- initStack -----
 |  Parameters:
 |      int n (IN) -- Size of Stack
 |
 |  Returns:
 |      struct stack (OUT) -- Returns initialised stack
 *-------------------------------------------------------------------*/
struct stack* initStack(int n) {
    struct stack* s = malloc(sizeof(struct stack));
    s->arr = malloc(n*sizeof(int));
    s->size = n;
    s->top = -1;

    return s;
}


/*--------------------------------------------------------- push -----
 |  Purpose: Pushes int val to stack if stack is not full yet
 |
 |  Parameters:
 |      struct stack s (IN) -- Stack
 |      int val (IN) -- Integer to be pushed to Stack
 *-------------------------------------------------------------------*/
void push(struct stack *s, int val) {
    if(s->top < s->size-1) {
        s->top++;
        s->arr[s->top] = val;

    } // else: stack overflow
}


/*---------------------------------------------------------- pop -----
 |  Purpose: Pops top int value of stack: Returns top int and  
 |      reduces top index (= removes top int)
 |
 |  Parameters:
 |      struct stack s (IN) -- Stack
 |
 |  Returns:
 |      int (OUT) -- Returns popped int
 *-------------------------------------------------------------------*/
int pop(struct stack *s) {
    if(s->top > -1) {
        int popped = s->arr[s->top];
        s->top--;
        return popped;
    }
    // else: stack overflow
    return -1;
}


/*--------------------------------------------------- printStack -----
 |  Purpose: Prints Stack by iterating through stack->arr
 |
 |  Parameters:
 |      struct stack s (IN) -- Stack
 *-------------------------------------------------------------------*/
void printStack(struct stack *s) {
    printf("[");
    int i = 0;
    while(i <= s->top && s->top > -1) {
        printf(" %d ", s->arr[i]);
        i++;
    }
    printf("]\n");
}




/* Try it out: returns 
 * []
 * [ 1 2 999 ]
 * [ 1 2 3 4 5 ] */
int main() {
    struct stack *s = initStack(5);
    printStack(s);
    push(s,1);
    push(s,2);
    push(s,999);
    printStack(s);
    pop(s);
    push(s,3);
    push(s,4);
    push(s,5);
    printStack(s);
 
    return 0;
}
