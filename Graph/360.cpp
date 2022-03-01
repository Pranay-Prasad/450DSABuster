// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
#include<bits/stdc++.h>
using namespace std;
bool iscycle(int src,vector<int>adj[],vector<bool>&vis,int prev){
    vis[src] = true;
    for(auto x:adj[src]){
        if(x != prev){
            if(vis[x]) return true;
            if(!vis[x] && iscycle(x,adj,vis,src)) return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i = 0; i < m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans = false;
    vector<bool>vis(n,false);
    for(int i = 0; i < n;i++){
        if(!vis[i] && iscycle(i,adj,vis,-1)){
            ans = true;
        }
    }
    (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}