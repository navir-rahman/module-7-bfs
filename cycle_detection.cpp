#include <bits/stdc++.h>
using namespace std;
const int E=1e3+5;
vector<int> adj[E];
bool visited[E];


bool dfs(int u, int p=-1)
{
    bool cycleExist = false;
    visited[u]=true;
    for(int v:adj[u])
    {
        if(p==v) continue;
        if(visited[v]) return true;
        cycleExist= cycleExist| dfs(v, u);

    }
    return cycleExist;
}

int main(){

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u >>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    // if(dfs(1, -1)){
    //     cout<< "yes\n";
    // }
    // else cout<<"no\n";

    bool iscycle = false;
    for (int i = 0; i <= n; i++)
    {
        if(visited[i]) continue;
        iscycle |= dfs(i);
    }
    
    if(iscycle){
        cout<< "yes\n";
    }
    else cout<<"no\n";
    
    
    return 0;
}