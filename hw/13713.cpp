#include<stdio.h>
#include<stdlib.h>

#define V 1000
#define INF 99999999

// record the min distance value
int mindistance=INF; 
int graph[V][V];

int BellmanFord(int n,int s,int f, int k)
{
 int dist[V];
 for(int i=0; i<=n; i++)
 {
        dist[i] = INF;
    }
    dist[s]=0;
    for(int i=1; i<=k; i++)
 { 
        for(int j=1; j<=n; j++)
  {
            for(int k=1; k<=n; k++)
   {
                if(dist[j] + graph[j][k] < dist[k])
    {
                    dist[k] = dist[j] + graph[j][k];
                }
            }
        }
    }
    
    return dist[f];
}


int main()
{
 int n, e;
 int s, f, k;
 int u, v, w;
 
 scanf("%d%d", &n, &e);
 scanf("%d%d%d", &s, &f, &k);
 
 // Init process
 for(int i = 0; i <= n; i++)
 {
  for(int j = 0; j <= n; j++)
  {
   graph[i][j] = INF; // init all graph distance are INF (unreachable)
  }
 }
 
 // Graph assignment
 for(int i = 0; i < e; i++)
 {
  scanf("%d%d%d", &u, &v, &w);
  graph[u][v] = w;
 }

 
 mindistance=BellmanFord(n, s, f, k);

 // Show results
 if(mindistance == INF)printf("-1\n");
 else printf("%d\n", mindistance);

 return 0;
}
