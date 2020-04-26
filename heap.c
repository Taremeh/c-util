/*-------------------------------------------------------- Heaps -----
 |  Author: Tarek Alakmeh
 |  Date:   April 2020
 |  Lang:   C (English)
 |
 |  Contents:
 |    MaxHeap with 2 or d nodes / children
 |      - heapify
 |      - heapify_d
 |      - buildMaxHeap
 |      - buildMaxHeap_d
 |
 *-------------------------------------------------------------------*/
 
 

/*---------------------------------------- heapify (buildMaxHeap) -----
 |  Function heapify (buildMaxHeap)
 |
 |  Purpose:  Check if heap condition holds (parent >= left && right 
 |      child). If not, switch parent with bigger child. Then call
 |      heapify recursively for the former parent, now comparing with
 |      its new children. (Trickle-Down)
 |
 |  Parameters:
 |      int A[] (IN) -- A[] is an (unsorted) int array. The function
 |              will restore heap condition for given branch (down-
 |              wards from i)
 |      int i (IN) -- i is the parent node that gets checked for the
 |              heap condition.
 |
 |  Returns:  n/a
 *-------------------------------------------------------------------*/
void heapify(A[], int i, int n) {
    // default maximum of parent and its children is current parent i
    int max = i;
    
    // right child
    if(i*2+2 < n && A[i*2+2] > A[i]) {
        max = i*2+2;
    }

    // left child
    if(i*2+1 < n && A[i*2+1] > A[i]
        &&  A[i*2+1] > A[i*2+2]) {
        max = i*2+1;
    }

    // if one of the children >= parent i, swap and call heapify rec.
    if(max != i) {
        int tmp = A[i];
        A[i] = A[max];
        A[max] = tmp;

        heapify(A, max, n);
    }

}



void heapify_d(A[], int i, int n, int d) {
    int max = i;

    // checking d children nodes from right to left
    for(int j = d*i+d; j > d*i; j--) {
        if(j < n && A[max] < A[j]) {
            max = j;
        }
    }

    if(max != i) {
        int tmp = A[i];
        A[i] = A[max];
        A[max] = tmp;

        heapify_d(A, max, n, d);
    }

}


/*------------------------------------------------- buildMaxHeap -----
 |  Function buildMaxHeap (up to 2 children per node)
 |
 |  Purpose:  buildMaxHeap heapifies the given array node by node. The
 |      heapify function gets called for all nodes/array indicies from
 |      0 - n/2 because the remaining nodes do not have children, there-
 |      fore already satisfying the heap condition.
 |
 |  Parameters:
 |      int A[] (IN) -- A[] is an (unsorted) int array. The function
 |              will convert the array to a MaxHeap structure.
 |
 |  Returns:  n/a
 *-------------------------------------------------------------------*/

void buildMaxHeap(int A[], int n) {
    for(int i = (n/2)-1; i >= 0; i--) {
        heapify(A,i,n);
    }
}

void buildMaxHeap_d(int A[], int n, int d) {
    for(int i = (n/d)-1; i >= 0; i--) {
        heapify_d(A, i, n, d);
    }
}
