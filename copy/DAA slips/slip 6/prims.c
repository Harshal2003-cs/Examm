/* write a c program for the implementation of prim's minimum */
/*    Algorithm
    step1 start
    step2 MST{}
    step3 Remove all loops and parallel edges
    step4 Choose a random vertex
    step5 select an edge 'e' having minimum weight and one vertex in tree
    step6  Add 'e' to the MST
    		
    step7 repeat from 5 till v-1 edges have been added
    step8 stop
*/
#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]= {0},min,mincost=0,cost[10][10];
void main() {
	
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
	   }
	visited[1]=1;
	printf("\n");
	while(ne<n) 
	{
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
		     if(visited[i]!=0) 
		     {
			min=cost[i][j];
			a=u=i;
			b=v=j;
		       }
		if(visited[u]==0 || visited[v]==0) 
		{
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Minimun cost=%d",mincost);

}	


/*
dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 6$ gcc prims.c
dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 6$ ./a.out

 Enter the number of nodes:7

 Enter the adjacency matrix:
0	28	0	0	0	10	0
28	0	16	0	0	0	14
0	16	0	12	0	0	0
0	0	12	0       22	0	0
0	0	0	22	0	25	24
10	0	0	0	25	0	0
0	14	0	0	24	0	0


 Edge 1:(1 6) cost:10
 Edge 2:(6 5) cost:25
 Edge 3:(5 4) cost:22
 Edge 4:(4 3) cost:12
 Edge 5:(3 2) cost:16
 Edge 6:(2 7) cost:14
 Minimun cost=99
*/

