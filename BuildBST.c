//
// Created by zht on 2018/10/25.
//
#include "BuildBST.h"

/*
 * this function will read the relationship between nodes
 * then build a tree with initial value INF
 */
Tree BuildTree(FILE* fp, int N){
    int index; /* the index of current node */
    Tree T;
    T = (Tree)calloc(sizeof(struct TreeNode),(N)); /* initialize the tree */
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
    K = (int*)calloc(sizeof(int),(N)); /* initialize the key array */
    int i;
    for (i=0; i<N; i++){
        fscanf(fp,"%d",&K[i]);
    }
    return K;
}

/*
 * the function SortKey use Bubble Sort algorithm to sort the key
 * the keys will be sorted in ascending order
 */
void SortKey(int* A, int N){
    int i,j,temp;
    for (i=0; i<N-1; i++)
        for (j=0; j<N-i-1; j++)
            if (A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
}

/*
 * according to the characteristic of the Binary Search Tree
 * its in-order traversal is an ascending sequence
 * thus, we can insert the keys into the tree while do in-order traversal
 * then a Binary Search Tree is build
 */
void InOrderInsert(Tree T, int root){
    if (T[root].left != Empty){
        InOrderInsert(T, T[root].left);
    }
    T[root].value = *K; /* insert the value */
    K++; /* update the pointer */
    if (T[root].right != Empty){
        InOrderInsert(T, T[root].right);
    }
}
/*
 * level-order traversal by using queue
 * first enqueue the root node
 * while queue is not empty, dequeue the node and then enqueue its children
 */
void LevelOrder(Tree T){
    FILE* fp; /* the result file */
    if( (fp = fopen( "result.dat","wb")) == NULL )
    {
        printf( "Open File Failed\n");
        exit(1);
    }

    struct TreeNode queue[MaxTree], p;
    /* the head points to the front of the queue
     * the tail points to the rear of the queue
     */
    int head = 0, tail = 1;
    queue[0] = T[0];
    while (head != tail){ /* the queue is not empty */
        p = queue[head]; /* get the head of queue */
        head = (head+1) % MaxTree; /* update the head */
        fprintf(fp, "%d ", p.value); /* visit the node */
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