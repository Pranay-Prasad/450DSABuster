// Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.
#include<bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<int> adj[],vector<int>&stack,vector<bool>&vis){
    stack[src] = true;
    if(!vis[src]){
        vis[src] = true;
        for(auto x:adj[src]){
            if(!vis[x] && iscycle(x,adj,stack,vis)){
                return true;
            }
            if(stack[x] == true){
                return true;
            }
        }
    }
    stack[src] = false;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0; i < m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bool ans = false;
    vector<int>stack(n+1,0);
    vector<bool>vis(n+1,0);
    for(int i = 0; i < n;i++){
        if(!vis[i] && iscycle(i,adj,stack,vis)){
            ans = true;
        }
    }
    (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}