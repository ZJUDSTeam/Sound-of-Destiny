//
// Created by zht on 2018/10/25.
//

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
int* K; /* use pointer to represent an array that store the keys */

Tree BuildTree(int N);
int* GetKey(int N);
void SortKey(int* A, int N);
void InOrderInsert(Tree T, int root);
void LevelOrder(Tree T);

#endif //PROJECT2_BUILDBST_H
