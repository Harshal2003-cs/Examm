#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20

typedef struct
{
  int data[MAXSIZE];
  int top;
}STACK;
void initstack(STACK *ps)
{
  ps->top=-1;
}
void push(STACK *ps,int num)
{
  ps->top++;
  ps->data[ps->top]=num;
}

int pop(STACK *ps)
{
   return(ps->data[ps->top--]);
}

int isempty(STACK *ps)
{
  return(ps->top==-1);
}
int isfull(STACK *ps)
{
  return(ps->top==MAXSIZE);
}

void dfs(int m[10][10],int n)
{
  int i,v,w,found;
	int visited[20]={0};
	STACK s;
	initstack(&s);
	v=0;
visited[v]=1;
push(&s,v);
printf("v%d",v+1);
while(1)
{
  found=0;
   for(w=0;w<n;w++)
   {
      if((m[v][w]==1)&&(visited[w]==0))
      {
         push(&s,w);
         printf("v%d",w+1);
	 visited[w]=1;
         v=w;
         found=1;
          break;
      }

   }
if(found==0)
 if(isempty(&s))
    break;
    else
    v=pop(&s);
} 
}

int main()
{
   int m[10][10],n,i,j;
  printf("\nHow many Vertices:");
 scanf("%d",&n);
for(i=0;i<n;i++)
 for(j=0;j<n;j++)
  {
      if(i!=j)
         {
           printf("Is there an edge between vertex %d and %d (1/0)",i+1,j+1);
            scanf("%d",&m[i][j]);
         }
  }

printf("Non recursive depth First Serach is");
dfs(m,n);
  return(0);
  }
