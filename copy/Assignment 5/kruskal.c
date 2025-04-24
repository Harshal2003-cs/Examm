
    #include<stdio.h>
    #include<stdlib.h>
    int i,j,k,a,b,u,v,n,ne=1;
    int min,mincost=0,cost[9][9],parent[9];
    int find(int);
    int uni(int,int);
    void main()
    {
    	printf("\n\tImplementation of Kruskal's algorithm\n");
    	printf("\nEnter the no. of vertices:");
    	scanf("%d",&n);
    	printf("\nEnter the cost adjacency matrix:\n");
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=n;j++)
    		{
    			scanf("%d",&cost[i][j]);
    			if(cost[i][j]==0)
    				cost[i][j]=999;
    		}
    	}
    	printf("The edges of Minimum Cost Spanning Tree are\n");
    	while(ne < n)
    	{
    		for(i=1,min=999;i<=n;i++)
    		{
    			for(j=1;j<= n;j++)
    			{
    				if(cost[i][j] < min)
    				{
    					min=cost[i][j];
    					a=u=i;
    					b=v=j;
    				}
    			}
    		}
    		
    		   printf("\nu=%d",u);
    		   printf("\nv=%d",v);
    		   
    		u=find(u);
    		v=find(v);
    		    printf("\nafter u=%d",u);
    		   printf("\nafter V=%d",v);
    		   
    		if(uni(u,v))
    		{
    			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
    			mincost +=min;
    		}
    		cost[a][b]=cost[b][a]=999;
    	}
    	printf("\n\tMinimum cost = %d\n",mincost);
    	
    }
    int find(int i)
    {
         printf("\n parent[i]=%d",parent[i]);
    	while(parent[i])
    	 i=parent[i];
    	
    	printf("\ni= %d",i);
    	return i;
    }
    int uni(int i,int j)
    {
    	if(i!=j)
    	{
    		parent[j]=i;
    		return 1;
    	}
    	return 0;
    }
    
    /*
    dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 5$ ./a.out

	Implementation of Kruskal's algorithm

Enter the no. of vertices:7

Enter the cost adjacency matrix:
0	28	0	0	0	10	0
28	0	16	0	0	0	14
0	16	0	12	0	0	0
0	0	12	0       22	0	0
0	0	0	22	0	25	24
10	0	0	0	25	0	0
0	14	0	0	24	0	0
The edges of Minimum Cost Spanning Tree are
1 edge (1,6) =10
2 edge (3,4) =12
3 edge (2,7) =14
4 edge (2,3) =16
5 edge (4,5) =22
6 edge (5,6) =25

	Minimum cost = 99
*/
	
	
