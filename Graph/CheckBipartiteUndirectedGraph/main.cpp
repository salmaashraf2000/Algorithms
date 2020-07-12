#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int const N=1e5+5;
vector<int> adj[N];
bool vis[N],col[N],isBipartite=1;

void DFS(int u, int p)
{
    vis[u]=1;
    for (int v : adj[u])
    {
            if(!vis[v])
            {
                col[v]=!col[u];
                DFS(v,u);
            }
            if(vis[v] && col[v]==col[u])
            isBipartite = 0;

    }
}
/*1 0
2 3
3 4
3 0
1 2*/
int main()
{
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            col[i]=0;
            DFS(i,-1);
        }
    }
    if(isBipartite) puts("Bipartite");
    else puts("NOT Bipartite");
    return 0;
}
