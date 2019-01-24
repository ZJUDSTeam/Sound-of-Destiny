/*
 * here are the definitions of functions we used
 */
#include "BuildBST.h"

/*
 * this function will read the relationship between nodes
 * then build a tree with initial value INF
 */
Tree BuildTree(FILE* fp, int N){
    int index; /* the index of current node */
    Tree T;
    T = (Tree)malloc(sizeof(struct TreeNode)*N); /* initialize the tree */
    if (T==NULL){
        printf("Error! Can't allocate memory!\n");
        return 0;
    }
    /* read the parent-child relationship and build the tree */
    for (index=0; index<N; index++){
        /* get the index of left child and right child */
        int left_index, right_index;
        fscanf(fp, "%d%d", &left_index,&right_index);
        T[index].left = left_index;
        T[index].right = right_index;
        T[index].value = INF; /* set the initial value */
    }
    return T;
}

/*
 * the function GetKey will read the given keys
 */
int* GetKey(FILE* fp, int N){
    int* K;
    K = (int*)malloc(sizeof(int)*N); /* initialize the key array */
    int i;
    for (i=0; i<N; i++){
        fscanf(fp,"%d",&K[i]); /* get the key */
    }
    return K;
}


/*
 * the function SortKey use Quick Sort algorithm to sort the key
 * the keys will be sorted in ascending order
 */
void SortKey(int* A, int left, int right){
    int i,j,temp,key;
    key = A[left]; /* set a key to compare */
    i = left; j = right;
    while (i<j){
        while (i<j && A[j]>=key)
            j--;
        A[i] = A[j];
        while (i<j && A[i]<=key)
            i++;
        A[j] = A[i];
    }
    A[j] = key;
    if (left < j-1)
        SortKey(A,left,j-1);
    if (j+1 < right)
        SortKey(A,j+1,right);
}

/*
 * according to the characteristic of the Binary Search Tree
 * its in-order traversal is an ascending sequence
 * thus, we can insert the keys into the tree while do in-order traversal
 * then a Binary Search Tree is build
 */
void InOrderInsert(Tree T, int root, int* K, int* index){
	if (T[root].left != Empty){
        InOrderInsert(T, T[root].left, K, index);
    }
    T[root].value = K[(*index)++]; /* insert the value */
    if (T[root].right != Empty){
        InOrderInsert(T, T[root].right, K, index);
    }
}

/*
 * level-order traversal by using queue
 * first enqueue the root node
 * while queue is not empty, dequeue the node and then enqueue its children
 */
void LevelOrder(Tree T){

    struct TreeNode queue[MaxTree], p;
    /* the head points to the front of the queue
     * the tail points to the rear of the queue
     */
    int head = 0, tail = 1;
    queue[0] = T[0];
    while (head != tail){ /* the queue is not empty */
        p = queue[head]; /* get the head of queue */
        head = (head+1) % MaxTree; /* update the head */
        printf("%d ", p.value); /* visit the node */
        if (p.left != Empty){ /* if the current node has left children, let it enqueue */
            queue[tail] = T[p.left];
            tail = (tail+1) % MaxTree; /* prevent array subscripts from crossing the boundary  */
        }
        if (p.right != Empty){ /* if the current node has right children, let it enqueue */
            queue[tail] = T[p.right];
            tail = (tail+1) % MaxTree; /* prevent array subscripts from crossing the boundary  */
        }
    }
}
