/*---------------------------------------------------- Quicksort -----
 |  Author: Tarek Alakmeh
 |  Date:   April 2020
 |  Lang:   C (English)
 |
 |  Contents:
 |
 |    Quicksort using LomutoPartition
 |      - lomutoPartition
 |      - quicksort
 |
 |
 |  (using swap function from ../commons.c)
 *-------------------------------------------------------------------*/


/*----------------------------------------------- lomutoPartition -----
 |  Function lomutoPartition
 |
 |  Purpose: Partition Array into: <= pivot | pivot | >= pivot
 |
 |  Parameters:
 |      int A[] (IN) -- Array to be partitioned
 |      int l (IN) -- left bound of array to be partitioned
 |                      (start with l = 0)
 |      int r (IN) -- right bound of array to be partitioned
 |                      (start with r = n-1)
 |
 |  Returns:  n/a
 *-------------------------------------------------------------------*/
int lomutoPartition(A[], l, r) {
    int pivot = A[r];
    int i = l-1; // initially l-1 = 0

    for(int j = l; j < r; j++) {
        if(A[j] <= pivot) {
            i = i+1;
            swap(&A[i], &A[j]);
        }

    }

    swap(&A[i+1], &A[r]); // swap first element of bigger part (= middle) with pivot

    return i+1; // first index of >= pivot part of array (middle)
}



/*--------------------------------------------------- quicksort -----
 |  Function quicksort
 |
 |  Purpose: Sort Array inplace in O(n log n) time using
 |    lomutoPartition. Divide and conquer array by recursively
 |    partitioning array.
 |
 |  Parameters:
 |      int A[] (IN) -- Array to be sorted
 |      int l (IN) -- left bound of array to be partitioned
 |                      (start with l = 0)
 |      int r (IN) -- right bound of array to be partitioned
 |                      (start with r = n-1)
 |
 |  Returns:  n/a
 *-------------------------------------------------------------------*/
void quicksort(A[], l, r) {
    if(l < r) {
        int m = lomutoPartition(A,l,r);
        quicksort(A, l, m-1);
        quicksort(A, m+1, r);
    }

}
