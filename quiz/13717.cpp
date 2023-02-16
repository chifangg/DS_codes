#include<stdio.h>
#include<stdlib.h>
#define V 1005
#define INF 99999999

int main()
{
 int n,e,m;
 int from, to, leng;
 int graph[V][V];
 int count[V];
 int max=-1;
 int ansnode;
 int dist[V][V];
 
    scanf("%d %d", &n, &e);
    scanf("%d", &m);
    int node=n;
    int mm=m;
    
     for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++)
	    {
		    if (i!=j)
		    graph[i][j]=INF;
		    else
		    graph[i][j]=0;
	 	}
        
    for (int i=0;i<e;i++)
    {
	    scanf("%d %d %d", &from, &to, &leng);
	    graph[from][to]=leng;
	    graph[to][from]=leng;
	}
 
    
 
    for (int i = 0; i < node; i++)
        for (int j = 0; j < node; j++)
            dist[i][j] = graph[i][j];
 
    for (int k = 0; k < node; k++) 
	{
        for (int i = 0; i < node; i++) 
		{
            for (int j = 0; j < node; j++) 
			{
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    for (int i = 0; i < node; i++) 
	{ 
     	count[i]=0;
        for (int j = 0; j < node; j++)
		{
            if (dist[i][j] <=m && i!=j)
                count[i]++;
        } 
		if (count[i]>=max) 
		{
		   max=count[i];
		   ansnode=i;
		}
    }
    printf("%d\n",ansnode);
    for (int i=0;i<node;i++)
    {
       if (dist[ansnode][i]<=m && ansnode!=i)
         printf("%d ", i);
   	}
   	printf("\n");
    return 0;
}
