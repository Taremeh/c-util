  
/*-------------------------------------------------- Double Hash -----
 |  Author: Tarek Alakmeh
 |  Date:   Mai 2020
 |  Lang:   C (English)
 |  Note:   Hash table for storing positive integers
 |
 |    Hash using double hash method for collision resolution
 |      - initHash
 |      - h
 |      - insert
 |      - search
 |      - printHash
 |      - main (example)
 |
 |
 |  (constant m sets hash table size) 
 *-------------------------------------------------------------------*/
#include <stdio.h>
#define m 7


/*----------------------------------------------------- initHash -----
 |  Purpose: Inits hash table with non-positive value 0
 *-------------------------------------------------------------------*/
void initHash(int A[]) {
    for(int i = 0; i < m; i++){
        A[i] = 0;
    }
}


/*------------------------------------------------------------ h -----
 |  Purpose: Computes hash key given the key k and probe i
 |
 |  Returns:
 |      int (OUT) -- Returns hashed key (hash table array index)
 *-------------------------------------------------------------------*/
int h(int k, int i) {
    int h1 = (k % m) + 1;
    int h2 = (m - 1) - (k % (m - 1));
    return (h1 + i*h2) % m;
}



/*------------------------------------------------------ insert -----
 |  Purpose: Inserts key into hash table
 |
 |  Parameters:
 |      int A[] (IN) -- Hash table
 |      int key (IN) -- Key to be inserted
 *-------------------------------------------------------------------*/
void insert(int A[], int key) {
    int i = 0;

    while(A[h(key, i)] != 0) {
        if(i < m-1) {
            i++;
        } else {
            return; // table full
        }
    }

    A[h(key, i)] = key;
}

/*------------------------------------------------------ search -----
 |  Purpose: Searches for key in hash table and returns 
 |
 |  Parameters:
 |      int A[] (IN) -- Hash table
 |      int key (IN) -- Key to be searched
 |
 |  Returns:
 |      int (OUT) -- Returns hash key (hash table array index) / -1
 *-------------------------------------------------------------------*/
int search(int A[], int key) {

    int i = 0;

    while(A[h(key, i)] != key) {
        if(i < m-1) {
            i++;
        } else {
            break;
        }
    }

    if(A[h(key, i)] == key) {
        return h(key, i);
    } else {
        return -1;
    }

}


/*---------------------------------------------------- printHash -----
 |  Purpose: Prints hash table (non empty entries)
 *-------------------------------------------------------------------*/
void printHash(int A[]) {
    printf("Table size: %d\n",m);
    for(int i = 0; i < m; i++){
        if(A[i] != 0) {
            printf("i: %d\tkey: %d\n", i, A[i]);
        }
    }
}


/*
 * Try it
 */
int main() {

    int A[m];

    init(A);
    insert(A, 2626);
    insert(A, 2628);
    insert(A, 2620);
    insert(A, 4000);
    insert(A, 4002);

    printf("\nSearch for 2626: A[%d] = %d", search(A, 2626), A[search(A, 2626)]);
    printf("\nSearch for 10 returns %d", search(A, 10));

    printHash(A);

    return 0;
}
