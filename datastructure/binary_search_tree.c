/*------------------------------------------- Binary Search Tree -----
 |  Author: Tarek Alakmeh
 |  Date:   Mai 2020
 |  Lang:   C (English)
 |
 |    struct
 |      - TreeNode
 |
 |    functions
 |      - insert
 |      - search
 |      - maximum
 |      - minimum
 |      - distanceToRoot
 |      - deleteNode (& getParentNode)
 |      - printTree (& printTreeRec)
 |      - main (example)
 |
 |    extra
 |      - lowCmnAnc (lowest common ancestor)
 |      - main (example)
 |
 *-------------------------------------------------------------------*/
 
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* l;
    struct TreeNode* r;
};


/*------------------------------------------------------- insert -----
 |  Purpose: Inserts value as new node at correct position in tree
 |
 |  Parameters:
 |      struct TreeNode* &root (IN) -- Root node address
 |      int val (IN) -- Integer to be inserted into tree
 *-------------------------------------------------------------------*/
void insert(struct TreeNode** root, int val) {

    struct TreeNode* current = *root;

    struct TreeNode* newTreeNode = malloc(sizeof(struct TreeNode));

    newTreeNode->val = val;
    newTreeNode->r = NULL;
    newTreeNode->l = NULL;


    /* while traversing the tree, the parentNode will be logged for every iteration, so when finding the
     *  correct current position for the new value (whose node current == NULL), using the parentNode will
     *  enable the insertion of the new value as a child. Without the logged parentNode, the traversal node
     *  will be just current == NULL without any properties */
    struct TreeNode* parentNode = NULL;

    while(current != NULL) {
        parentNode = current;
        if(newTreeNode->val > current->val) {
            current = current->r;
        } else {
            current = current->l;
        }
    }

    if(parentNode == NULL) {
        *root = newTreeNode;
    } else if (newTreeNode->val > parentNode->val){
        parentNode->r = newTreeNode;
    } else {
        parentNode->l = newTreeNode;
    }
}


/*------------------------------------------------------- search -----
 |  Purpose: Searches value, returns its node if found (else NULL)
 |
 |  Parameters:
 |      struct TreeNode* root (IN) -- Root node
 |      int val (IN) -- Integer to be searched
 |
 |  Returns:
 |      struct TreeNode* (OUT) -- Returns searched node / NULL
 *-------------------------------------------------------------------*/
struct TreeNode* search(struct TreeNode* root, int val) {
    if(root == NULL) {
        return root; // empty tree
    }

    struct TreeNode* current = root;
    struct TreeNode* foundNode = NULL;

    while(current != NULL){
        if(current->val == val) {
            foundNode = current;
            break;
        } else if (val > current->val) {
            current = current->r;
        } else {
            current = current->l;
        }
    }

    return foundNode;
}


/*------------------------------------------------------ maximum -----
 |  Purpose: Searches maximum value in subtree (starting from given node
 |    downwards). Returns maximum node.
 |
 |  Parameters:
 |      struct TreeNode* node (IN) -- Starting node for maximum search
 |
 |  Returns:
 |      struct TreeNode* (OUT) -- Returns maximum node of subtree
 *-------------------------------------------------------------------*/
struct TreeNode* maximum(struct TreeNode* node) {
    struct TreeNode* current = node;

    while(current->r != NULL) {
        current = current->r;
    }

    return current;
}


/*------------------------------------------------------ minimum -----
 |  Purpose: Searches minimum value in subtree (starting from given node
 |    downwards). Returns minimum node.
 |
 |  Parameters:
 |      struct TreeNode* node (IN) -- Starting node for minimum search
 |
 |  Returns:
 |      struct TreeNode* (OUT) -- Returns minimum node of subtree
 *-------------------------------------------------------------------*/
struct TreeNode* minimum(struct TreeNode* node) {
    struct TreeNode* current = node;

    while(current->l != NULL) {
        current = current->l;
    }

    return current;
}


/*------------------------------------ getParentNode (deleteNode) -----
 |  Purpose: Help function for deleteNode. Finds and returns parentNode
 |    of given node n.
 |
 |  Parameters:
 |      struct TreeNode* n (IN) -- Starting node for parent search
 |      struct TreeNode* child (IN) -- Child node
 |
 |  Returns:
 |      struct TreeNode* (OUT) -- Returns parentNode of child
 *-------------------------------------------------------------------*/
struct TreeNode* getParentNode(struct TreeNode* n, struct TreeNode* child) {
    if(n == NULL) {
        return n; // empty tree
    }

    struct TreeNode* current = n;
    struct TreeNode* parentNode = NULL;

    while(current != NULL){
        if(current == child) {
            break;
        }

        parentNode = current;

        if (child->val > current->val) {
            current = current->r;
        } else {
            current = current->l;
        }
    }

    return parentNode;
}


/*--------------------------------------------------- deleteNode ------
 |  Purpose: Deletes node from tree in respect to tree conditions.
 |
 |  Parameters:
 |      struct TreeNode* &root (IN) -- Root node address
 |      int val (IN) -- Value of node to be deleted
 *-------------------------------------------------------------------*/
void deleteNode(struct TreeNode** root, int val) {
    if(*root == NULL) {
        return; // empty tree
    }

    struct TreeNode* current = *root;
    struct TreeNode* parentNode = current;
    struct TreeNode* deleteNode = NULL;


    /* Find deleteNode & deleteNodes parentNode in tree */
    while(current != NULL) {

        if(current->val == val) {
            // found deleteNode
            deleteNode = current;
            break;
        }

        parentNode = current;

        if(val > current->val) {
            current = current->r;
        } else {
            current = current->l;
        }
    }

    /* Handle delete of node without violating binary tree conditions */
    if(deleteNode == NULL) {
        // deleteNode not found
    } else if (deleteNode->l == NULL){
        /* left subtree empty */
        if(deleteNode->r == NULL) {
            /* right subtree empty */

            if(parentNode->r == deleteNode) {
                parentNode->r = NULL;
            } else {
                parentNode->l = NULL;
            }
            free(deleteNode);

        } else {
            /* right subtree exists */
            struct TreeNode* minimumSubNode = minimum(deleteNode->r);
            
            // Get minimumSubNode parentNode and remove link to minimumSubNode
            struct TreeNode* parentNode = getParentNode(*root,minimumSubNode);
            if(parentNode->l == minimumSubNode) {
                parentNode->l = NULL;
            } else if (parentNode->r == minimumSubNode) {
                parentNode->r = NULL;
            }
         
            deleteNode->val = minimumSubNode->val; // replace deleteNode with minimum of subtree
            free(minimumSubNode);
        }
    } else {
        /* left subtree exists */
        struct TreeNode* maximumSubNode = maximum(deleteNode->l);

        // Get maximumSubNode parentNode and remove link to maximumSubNode
        struct TreeNode* parentNode = getParentNode(*root,maximumSubNode);
        if(parentNode->l == maximumSubNode) {
            parentNode->l = NULL;
        } else if (parentNode->r == maximumSubNode) {
            parentNode->r = NULL;
        }

        deleteNode->val = maximumSubNode->val; // replace deleteNode with maximum of subtree
        free(maximumSubNode);
    }

}


/*----------------------------------------------- distanceToRoot ------
 |  Parameters:
 |      struct TreeNode* root (IN) -- Root node
 |      int val (IN) -- Value of target node
 |
 |  Returns:
 |      int (OUT) -- Returns distance from root to target node
 *-------------------------------------------------------------------*/
int distanceToRoot(struct TreeNode* root, int val) {
    if(root == NULL) {
        return 0; // empty tree
    }

    struct TreeNode* current = root;

    int i = 0;
    while(current != NULL){
        if(current->val == val) {
            break;
        } else if (val > current->val) {
            current = current->r;
        } else {
            current = current->l;
        }
        i++;
    }

    return i;

}


/*------------------------------------- printTreeRec (printTree) ------
 |  Purpose: Helper function for printTree. Traverses tree recursively
 |    while printing traversed node values.
 |
 |  Parameters:
 |      struct TreeNode* n (IN) -- Starting node
 *-------------------------------------------------------------------*/
void printTreeRec(struct TreeNode* n) {
    if(n == NULL) {
        return;
    }

    if(n->l != NULL){ printf("  %d -- %d\n",n->val, n->l->val); }
    if(n->r != NULL){ printf("  %d -- %d\n",n->val, n->r->val); }

    if(n->l != NULL) {
        printTreeRec(n->l);
    }
    if(n->r != NULL) {
        printTreeRec(n->r);
    }

}


/*---------------------------------------------------- printTree ------
 |  Purpose: Prints trees node links as graph data
 |
 |  Parameters:
 |      struct TreeNode* n (IN) -- Starting node
 *-------------------------------------------------------------------*/
void printTree(struct TreeNode* n) {
    printf("graph g {\n");
    if(n->l == NULL && n->r == NULL) {
        // only 1 node (root) in tree
        printf("  %d\n", n->val);
    } else {
        printTreeRec(n);
    }

    printf("}");
}


/* Try it out */
int main() {
    struct TreeNode* root = NULL;
    insert(&root, 10);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 1);
    insert(&root, 20);
    insert(&root, 11);
    insert(&root, 15);
    insert(&root, 25);
    printTree(root);
    printf("\nDistance to root of node 25: %d\n\n",distanceToRoot(root,25));
    printf("Deleting: 10, 11, 15\n");
    deleteNode(&root, 10);
    deleteNode(&root, 11);
    deleteNode(&root, 15);
    printTree(root);
    printf("\nMaximum Value: %d", maximum(root)->val);
    printf("\nDistance to root of node 6: %d",distanceToRoot(root,6));

    return 0;
}




/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *           Extra Functionality for Binary Search Trees             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*-------------------------------------------------- lowCmnAnc ------
 |  Parameters:
 |      struct TreeNode* root (IN) -- Root node
 |      struct TreeNode* n1 (IN) -- Child node 1
 |      struct TreeNode* n2 (IN) -- Child node 2
 |
 |  Returns:
 |      struct TreeNode* (OUT) -- Lowest common ancestor node
 |          (assuming every node is ancestor of itself)
 *-------------------------------------------------------------------*/
struct TreeNode* lowCmnAnc(struct TreeNode* root, struct TreeNode* n1, struct TreeNode* n2) {
    if(root == NULL) { return NULL; }
    if(n1->val < root->val && n2->val < root->val) {
        return lowCmnAnc(root->l, n1, n2);
    }
    if(n1->val > root->val && n2->val > root->val) {
        return lowCmnAnc(root->r, n1, n2);
    }

    return root;
}


/* Try it out: returns
 * Lowest common ancestor of 10 and 18 is: 16
 */
int main() {
    struct TreeNode* root = NULL;
    insert(&root, 28); insert(&root, 30); insert(&root, 16);
    insert(&root, 10); insert(&root, 21); insert(&root, 18);
    insert(&root, 24);


    int c1 = 10; int c2 = 18;
    printf("\nLowest common ancestor of %d and %d is: %d", c1, c2, lowCmnAnc(root, search(root, c1),  search(root, c2))->val);

    return 0;
}
