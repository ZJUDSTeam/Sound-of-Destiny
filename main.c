//
// Created by 59932 on 2018/10/23.
//
<<<<<<< HEAD
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
=======
int foo(int n);
#include <stdio.h>
int main(void)
{
    printf("%d",foo(10));

}


int foo(int n)
{
    static int a = 0;
    if( n != 0 )
    {
        a++;
        foo(n-1);
    }
    return a;
}




>>>>>>> origin/master
