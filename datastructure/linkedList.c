/*--------------------------------------------------- LinkedList -----
 |  Author: Tarek Alakmeh
 |  Date:   April 2020
 |  Lang:   C (English)
 |
 |    struct
 |      - node
 |      - list
 |
 |    functions
 |      - initNode
 |      - initLinkedList
 |      - appendAtTail
 |      - appendAtHead
 |      - appendAtPosition
 |      - size
 |      - printList
 |      - deleteNode (TODO)
 |      - main
 |
 *-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
int size();


struct node {
    int val;
    struct node* next;
};

struct list {
    struct node* head;
    struct node* tail;
};


/*----------------------------------------------------- initNode -----
 |  Parameters:
 |      int val (IN) -- Node Value
 |
 |  Returns:
 |      struct node (OUT) -- Returns initialised node
 *-------------------------------------------------------------------*/
struct node* initNode(int val) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

/*----------------------------------------------- initLinkedList -----
 |  Returns:
 |      struct list (OUT) -- Returns initialised node
 *-------------------------------------------------------------------*/
struct list* initLinkedList() {
    struct list* l = malloc(sizeof(struct list));
    l->head = NULL;
    l->tail = NULL;

    return l;
}



/*-------------------------------------------------- appendAtTail -----
 |  Purpose:  Add node to the end of linkedList
 |
 |  Parameters:
 |      struct list l (IN) -- LinkedList
 |      int val (IN) -- Node Value
 *-------------------------------------------------------------------*/
void appendAtTail(struct list* l, int val) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    // struct node* new_node = initNode(val); // alternatively


    if (l->tail == NULL) {
        l->head = new_node;
        l->tail = new_node;

        //printf("\nl->head->next: %p\n", &l->head->next);
        //printf("\nnew_node->next: %p\n", &new_node->next);

    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

/*------------------------------------------------- appendAtHead -----
 |  Purpose:  Add node to the start of linkedList
 |
 |  Parameters:
 |      struct list l (IN) -- LinkedList
 |      int val (IN) -- Node Value
 *-------------------------------------------------------------------*/
void appendAtHead(struct list* l, int val) {
    struct node* new_node = initNode(val);

    if(l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        new_node->next = l->head;
        l->head = new_node;
    }

}


/*--------------------------------------------- appendAtPosition -----
 |  Purpose:  Add node at stated position
 |
 |  Parameters:
 |      struct list l (IN) -- LinkedList
 |      int val (IN) -- Node Value
 |      int post (IN) -- Position of new node (pos = 0,1,2,...,n-1)
 *-------------------------------------------------------------------*/
void appendAtPosition(struct list* l, int val, int pos) {

    /* Switch to prior methods if head / tail needs to be updated */
    if(pos == 0) {
        appendAtHead(l, val);
        return;
    } else if (pos == size(l)) {
        appendAtTail(l, val);
        return;
    }

    struct node* new_node = initNode(val);

    struct node* n = l->head;
    int i = 0;

    while(n->next != NULL && i < pos-1) {
        n = n->next;
        i++;
    }

    new_node->next = n->next;
    n->next = new_node;

}


/*--------------------------------------------------------- size -----
 |  Returns:
 |      int size (OUT) -- Returns size of linkedList
 *-------------------------------------------------------------------*/
int size(struct list* l) {
    struct node *n = l->head;

    int i = 0;
    while(n != NULL) {
        n = n->next;
        i++;
    }
    return i;
}


/*---------------------------------------------------- printList -----
 |  Purpose:
 |      Prints linkedList. i.e. [ 1 2 3 4 5 ]
 |
 |  Parameters:
 |      struct list l (IN) -- LinkedList
 *-------------------------------------------------------------------*/
void printList(struct list* l){
    printf("[");

    struct node* current = l->head;
    int i = 0;
    while(current != NULL) {
        printf(" %d ",current->val);
        current = current->next;
        i++;
    }
    
    printf("]");
}


/*---------------------------------------------------- deleteNode -----
 |  Purpose:
 |      Deletes node at position pos from linkedList
 |
 |  Parameters:
 |      struct list l (IN) -- LinkedList
 |      int pos (IN) -- Postion of node to be deleted
 *-------------------------------------------------------------------*/
void deleteNode(struct list *listA, int pos) {
    /* TODO */
}




/* Try it out (returns [ 0 1 2 3 4 5 ] */
int main() {

    struct list* l = initLinkedList();
    appendAtTail(l, 2);
    appendAtTail(l, 4);
    appendAtHead(l, 1);
    appendAtPosition(l, 3, 2);
    appendAtHead(l, 0);
    appendAtTail(l, 5);

    printList(l);
    printf("\nlinkedList size: %d",size(l));

    return 0;
}

