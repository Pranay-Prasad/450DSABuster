// There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, which is expressed as a pair: [0, 1]Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int>adj[],vector<bool>&vis,vector<int>&st,int i){
    st[i] = 1;
    if(!vis[i]){
        vis[i] = true;
        for(auto x:adj[i]){
            if(!vis[x] && dfs(adj,vis,st,x)) return true;
            if(st[x] == 1) return true;
        }
    }
    st[i] = 0;
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
    }
    bool cycle = false;
    vector<bool>vis(n,false);
    vector<int>st(n,0);
    for(int i = 0;i < n;i++){
        if(!vis[i] && dfs(adj,vis,st,i)) cycle = true;
    }
    (cycle)?cout<<"NO"<<endl:cout<<"YES"<<endl;
    return 0;
}