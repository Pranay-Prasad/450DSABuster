//Topological sorting
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<bool>&vis,stack<int>&s,int x){
    vis[x] = true;
    for(auto i : adj[x]){
        if(!vis[i]){
            dfs(adj,vis,s,i);
        }
    }
    s.push(x);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i = 0;i < m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    //Topological sorting code

    vector<bool>vis(n,false);
    stack<int>s;
    for(int i = 0; i < n;i++){
        if(!vis[i])
            dfs(adj,vis,s,i);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}