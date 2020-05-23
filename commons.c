/*------------------------------------------------------ Commons -----
 |  Author: Tarek Alakmeh
 |  Date:   April 2020
 |  Lang:   C (English)
 |
 |  Contents:
 |      - swap
 |      - printArray
 |      - duplicateArray
 |
 |
 *-------------------------------------------------------------------*/
 

/*--------------------------------------------------------- swap -----
 |  Function swap (variables, array variables)
 |
 |  Purpose:  Swap two variables. i.e. int a and int b, or A[i] and A[j]
 |
 |  Parameters:
 |      int &a (IN) -- Address of first element
 |      int &b (IN) -- Address of second element
 |
 |  Returns:  n/a
 *-------------------------------------------------------------------*/
void swap(int *p_x, int *p_y) {
    int tmp = *p_x;
    *p_x = *p_y;
    *p_y = tmp;
}


/*--------------------------------------------------- printArray -----
 |  Parameters:
 |      int A[] (IN) -- Prints array A
 *-------------------------------------------------------------------*/
void printArray(int A[], int n) {
    int i = 0;
    while(i < n) {
        printf("%d ", A[i]);
        i++;
    }
}


/*----------------------------------------------- duplicateArray -----
 |  Parameters:
 |      int A[] (IN) -- Input Array A
 |
 |  Returns:  int* pointer to duplicate array. Can be called like:
 |      int *B = duplicateArray(A, n);
 *-------------------------------------------------------------------*/
int* duplicateArray(int A[], int n) {
    int *B = malloc(n* sizeof(int));

    for(int i = 0; i < n; i++) {
        B[i] = A[i];
    }

    return B;
}
