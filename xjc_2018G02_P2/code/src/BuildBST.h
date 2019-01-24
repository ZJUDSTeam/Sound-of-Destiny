/*
 * here are the declarations of functions and data structures we used
 */
#ifndef PROJECT2_BUILDBST_H
#define PROJECT2_BUILDBST_H

#include <stdio.h>
#include <stdlib.h>
#define MaxTree (100) /* the max number of tree nodes */
#define Empty (-1) /* the value of empty node */
#define INF (0xFFFFFFF) /* the initial value of every tree node */

typedef struct TreeNode *Tree;
struct TreeNode{
    int value; /* the element value of every node */
    int left,right; /* the index of left node and right node */
};

Tree BuildTree(FILE* fp, int N);
int* GetKey(FILE* fp, int N);
void SortKey(int* A, int left, int right);
void InOrderInsert(Tree T, int root, int* K, int* index);
void LevelOrder(Tree T);

#endif 
