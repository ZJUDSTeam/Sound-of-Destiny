/*
 * here are the main program, including test part
 * the functions we called are defined in BuildBST.c
 * the data structures we used are declared in BuildBST.h
 */
#include "BuildBST.h"
/*
 * this program will build a binary tree and set the value of each node of binary tree to build a binary search tree
 */
int main(void)
{
	char test = 'y'; /*initialize the variable to judge whether to continue testing*/
	char filename[30] = "TestCaseX.dat"; /*char array to store file name*/
	char choice;
	Tree T;
	int* K;
	printf("---------------------------------");
	
	while(test == 'y' || test == 'Y')
	{
		int N; /* the number of the nodes */
		printf("\nPlease choose the TestCase:\n");
		printf("1.TestCase1\n2.TestCase2\n3.TestCase3\n4.TestCase4\n5.TestCase5\n6.TestCase6\n>>"); 
		/*choose the test case*/
		scanf("%c",&choice);
		/*get the enter char*/
		while(getchar() != '\n');
		
		if(choice >= '1' && choice <= '6')
		{
			FILE *fp;
			filename[8] = choice;  			/*set the file name*/
			int index = 0;
    		/* open the test data file */
    		if( (fp = fopen( filename,"r")) == NULL )
    		{
        		printf( "Open File Failed\n");
        		exit(1);
    		}
    
    		/*Input the number of node*/
    		fscanf(fp,"%d",&N);
    
    		/*Build a binary tree*/
    		T = BuildTree(fp,N);
    
    		/*Input the keys*/
    		K = GetKey(fp,N);
    
    		/*Sort the keys*/
    		SortKey(K,0,N-1);

    		/*Set the value of each node of binary tree to build a binary search tree*/
    		InOrderInsert(T,0,K,&index);
    
    		/*print the data of the node in level order*/
    		LevelOrder(T);
    		
    		/*free the memory allocated*/
    		free(T);
    		free(K);
    		
    		printf("\nContinue to test?(Y or N)\n>>");
    		scanf("%c",&test);
    		getchar();
		}
		
		else
			printf("Invalid Input\n");
	}
	
	return 0;
}

