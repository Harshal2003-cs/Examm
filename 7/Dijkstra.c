/*
     Dijkstra's Algorithm
    1 start
    2 V is the starting vertex
    3 Initialize visiting array to 0
    4 Initialize all elements of distance array as
     dist[i]=cost[v][i]
    5 mark v visited i.e visited[v]=1
    6 choose a vertex u which is unvisisted and dist[u] is minimum
    7 mark u visited
    8 for all vertices w adjacent to u
       if(w is not visited)
         if(dis[u]+cost[u][w]<dist[w])
         dist[w]=dist[u]+cost[u][w]
    9  repeat from 6 till all vertices are not visited
    10  Dist array contains the shortest paths from V to all other destinations.
    11  stop   
     
*/


#include<stdio.h>
int cost[9][9];
int i,j,u,w,n,count,min;
/*int cost[8][8]={
{0,999,999,999,999,999,999,999},
{30,0,999,999,999,999,999,999},
{100,80,0,999,999,999,999,999},
{999,999,120,0,999,999,999,999},
{999,999,120,0,999,999,999,999},
{999,999,999,150,0,25,999,999},
{999,999,999,100,999,0,90,140},
{999,999,999,999,999,999,0,100}
};*/

void dijkstra(int v,int n)
{
   //int i,j,u,w,count,min;
   int dist[10],visit[10]={0};
    visit[v]=1;
	for(i=0;i<n;i++)
        dist[i]=cost[v][i];
   count=2;
  while(count<n)
  {
    min=999;
   for(i=0;i<n;i++)
 	if(visit[i]==0 && dist[i]<min)
	{
  		min=dist[i];
 		u=i;
 	}
      visit[u]=1;
     for(w=0;w<n;w++)
	if(dist[u]+cost[u][w]<dist[w])
          dist[w]=dist[u]+cost[u][w];
		count++;
 }
      printf("\n Shortest distance from vetrtex %d are:\n",v);
       for(i=0;i<n;i++)
        printf("%d\t",dist[i]);
}

void main()
{
/*int cost[9][9];*/
printf("\n\tImplementation of Dijkstras algorithm\n");
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
    printf("\n the cost of  adjacency matrix:\n");
    	for(i=1;i<=n;i++)
    	{
    		for(j=1;j<=n;j++)
    		{
    			printf("%5d",cost[i][j]);
    			
    		}
    		printf("\n");
    	}
    
   dijkstra(2,6);
}

/*
999     999	999	30	999	999
40      999	30	999	20	999
999	999	999	999	999	10
999	999	999	999	10	999
15	999	2	5	999	5
999	999	999     999	20	999
dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 7$ gcc Dijkstra.c
dell@dell-OptiPlex-3000:~/Desktop/nisha/Assignment 7$ ./a.out

 Shortest distance from vetrtex 4 are:
220	200	120	0	999	999	999	999	
*/

