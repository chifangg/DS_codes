#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define NUM 200005
vector<int> child[NUM];
set<int> distinct[NUM];
// vector<int>
int n;
long long int v[NUM];
int parent[NUM];
int finish[NUM];
int whereset[NUM];
void dfs(int node)
{
    //visited[node]=1;
    whereset[node]=node;
    int largest=0;
    int a=0;
    for(auto it: child[node])
    {
        
        if(parent[node]!=it)
        {
            parent[it]=node;
            dfs(it);
            
        }    
        
    }
    for(auto it: child[node])
    {
        if(distinct[whereset[it]].size()>largest)
            {
                largest=distinct[whereset[it]].size();
                whereset[node]=whereset[it];
                a=it;
            }
    }
    for(auto it: child[node])
    {
        if(it!=parent[node] && it!=a)
        {
            for(auto p :distinct[whereset[it]])
                distinct[whereset[node]].insert(p);
        }
        
    }
        
    distinct[whereset[node]].insert(v[node]);
    finish[node]=distinct[whereset[node]].size();
}


int main()
{

 scanf("%d", &n);
 for(int i = 1; i <= n; i++)
 {
    scanf("%lld", &v[i]);
 }
 for(int i = 1; i < n; i++)
 {
    int a, b;
    scanf("%d %d", &a, &b);
    child[a].push_back(b);
    child[b].push_back(a);

 }
    dfs(1);
    for(int i=1; i<=n; i++)
    {
        printf("%d ", finish[i]);
    }
  printf("\n");
 return 0;
}
