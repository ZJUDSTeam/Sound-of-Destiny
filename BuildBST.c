//
// Created by zht on 2018/10/25.
//
#include "BuildBST.h"

Tree BuildTree(int N){
    int index;
    Tree T;
    T = (Tree)calloc(sizeof(struct TreeNode),(N));
    if (T==NULL){
        printf("Error! Can't allocate memory!\n");
        return 0;
    }
    for (index=0; index<N; index++){
        int left_index, right_index;
        scanf("%d%d", &left_index,&right_index);
        T[index].left = left_index;
        T[index].right = right_index;
        T[index].value = INF;
    }
    return T;
}

int* GetKey(int N){
    int* K;
    K = (int*)calloc(sizeof(int),(N));
    int i;
    for (i=0; i<N; i++){
        scanf("%d",&K[i]);
    }
    return K;
}

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

void LevelOrder(Tree T){
    struct TreeNode queue[MaxTree], p;
    int head = 0, tail = 1;
    queue[0] = T[0];
    while (head != tail){
        p = queue[head];
        head = (head+1) % MaxTree;
        printf("%d ", p.value);
        if (p.left != Empty){
            queue[tail] = T[p.left];
            tail = (tail+1) % MaxTree;
        }
        if (p.right != Empty){
            queue[tail] = T[p.right];
            tail = (tail+1) % MaxTree;
        }
    }
}