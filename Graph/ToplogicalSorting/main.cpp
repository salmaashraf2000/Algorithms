#include <iostream>
#include <bits/stdc++.h>
using namespace std;

///work with DAG only (directed acyclic graph)

const int N= 2e5+5;


vector<int> adj[N], ans;
int vis[N];

void dfs(int u){
    vis[u]=1;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
    }
    ans.push_back(u);
}


int main()
{
    int n,m, u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0; i<n; i++)
        if(!vis[i])
            dfs(i);

    reverse(ans.begin(), ans.end());
    for(int z: ans)cout<<z<<" ";
    return 0;
}
