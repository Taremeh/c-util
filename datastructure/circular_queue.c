/*--------------------------------------------- queue (circular) -----
 |  Author: Tarek Alakmeh
 |  Date:   Mai 2020
 |  Lang:   C (English)
 |  Note:   A queue is an abstract data type. Usually it would not be
 |            possible to print the entire queue without dequeuing all
 |            its values. However, the queue has been implemented in C
 |            using an underlying linkedList, which the function 
 |            printQueue iterates over to print the queue without
 |            dequeuing the values.
 |          IMPORTANT: The implemented queue is circular and operates
 |            as LIFO (Last In First Out) queue.
 |
 |    struct
 |      - node
 |      - queue (circular)
 |
 |    functions
 |      - initQueue
 |      - enQueue
 |      - deQueue
 |      - printQueue
 |      - main (example)
 |
 *-------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>


struct node {
    int val;
    struct node* next;
};

struct queue {
    struct node* head;
    struct node* tail;
};


/*---------------------------------------------------- initQueue -----
 |  Returns:
 |      struct stack (OUT) -- Returns initialised queue
 *-------------------------------------------------------------------*/
struct queue* initQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;

    return q;
}


/*------------------------------------------------------ enQueue -----
 |  Purpose: Enqueues an int val as last element of queue
 |
 |  Parameters:
 |      struct queue q (IN) -- Queue
 |      int val (IN) -- Integer to be enqueued to Queue
 *-------------------------------------------------------------------*/
void enQueue(struct queue *q, int val) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = q->head;   // making queue circular

    if(q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}


/*------------------------------------------------------ deQueue -----
 |  Purpose: Dequeues first int value of queue: Returns first int and  
 |      frees the memory of the dequeued node
 |
 |  Parameters:
 |      struct queue q (IN) -- Queue
 |
 |  Returns:
 |      int (OUT) -- Returns dequeued int
 *-------------------------------------------------------------------*/
int deQueue(struct queue *q) {
    int dequeued_val;

    if(q->head == NULL) {
        return -1; // empty queue
    } else if(q->head == q->tail) {
        // 1 last element in queue
        dequeued_val = q->head;
        free(q->head);
        q->head = NULL;
        q->tail = NULL;
    } else {
        // > 1 elements in queue
        dequeued_val = q->head->val;

        struct node* dequeued_node = q->head; // set pointer to current q->head, so the memory can be freed
        q->head = q->head->next; // set new q->head
        q->tail->next = q->head;
        free(dequeued_node); // free old q->head
    }

    return dequeued_val;
}


/*--------------------------------------------------- printQueue -----
 |  Purpose: Prints Queue by iterating through all queue nodes
 |
 |  Parameters:
 |      struct queue q (IN) -- Queue
 *-------------------------------------------------------------------*/
void printQueue(struct queue *q) {
    printf("[");

    if(q->head != NULL) {
        printf(" %d ", q->head->val);
        struct node *cur = q->head->next;
        while (cur != q->head) {
            printf(" %d ", cur->val);
            cur = cur->next;
        }
    }
    printf("]\n");
}


/* Try it out: returns 
 * [ 1  2  3  4  5  6 ]
 * [ 2  3  4  5  6 ] */
int main() {
    struct queue* q = initQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    enQueue(q, 6);
    printQueue(q);
    deQueue(q);
    printQueue(q);

    return 0;
}
