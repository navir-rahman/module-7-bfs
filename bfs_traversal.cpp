#include <bits/stdc++.h>
using namespace std;
const int E=1e3+5;
vector<int> adj[E];
bool visited[E];
int level[E];

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;

    level[s]=0;
    while (!q.empty())
    {
        //pop a node from the queue and insert
        //unvisited neighbors if that node
        int u =q.front();
        q.pop();
        // cout<<u<<endl;
        // section 1
        for(auto v:adj[u])
        {
            // section 2
            if(visited[v]== true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;
            // section 3
        }
        // section 4
    }
    
}



int main(){

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    bfs(1);
    for (int i = 0; i < n; i++)
    {
        cout<<level[i]<<endl;
    }
    
    
    return 0;
}