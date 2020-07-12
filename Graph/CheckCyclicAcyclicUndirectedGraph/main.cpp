#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N= 2e5+5;

vector<int> adj[N];
int vis[N];
bool cyclic;

void dfs(int u, int p){
    vis[u]=1;
    for(int v: adj[u]){
        if(!vis[v])dfs(v,u);
        else if(v!=p)cyclic=1;
    }
}

int main()
{
    int n,m, u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(u,-1);
    cout<<"There is "<<(cyclic? "a Cycle": "No cycle");
    return 0;
}
