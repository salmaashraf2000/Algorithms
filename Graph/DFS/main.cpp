#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N= 2e5+5;

vector<int> adj[N];
int vis[N];

void dfs(int u){
    vis[u] = 1;
    for(int v: adj[u]){
        if(!vis[v])
            dfs(v);
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
    int cnt =1;
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(i);
        else
            cnt++;
    }
    cout<<cnt;
    return 0;
}
