//
// Created by 59932 on 2018/10/23.
//

#include "BuildBST.c"

int main(void)
{
    int N; /* the number of the nodes */
    Tree T; /* define the tree */
    FILE *fp;
    /* open the test data file */
    if( (fp = fopen( "test.dat","r")) == NULL )
    {
        printf( "Open File Failed\n");
        exit(1);
    }
    fscanf(fp,"%d",&N);
    T = BuildTree(fp,N);
    K = GetKey(fp,N);
    SortKey(K,N);
    InOrderInsert(T,0);
    LevelOrder(T);
}

