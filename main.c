//
// Created by 59932 on 2018/10/23.
//
#include "BuildBST.c"


int main(void)
{
    int N; /* the number of the nodes */
    Tree T; /* define the tree */
    scanf("%d",&N);
    T = BuildTree(N);
    K = GetKey(N);
    SortKey(K,N);
    InOrderInsert(T,0);
    LevelOrder(T);
}