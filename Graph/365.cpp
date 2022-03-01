// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>adj[],vector<bool>&vis,int i){
    vis[i] = true;
    for(auto x:adj[i]){
        if(!vis[x]){
            solve(adj,vis,x);
        }
    }
}
int get_ans(vector<int>edge[],int n,int e){
    int count= 0;
    if(e < n-1) return -1;
    vector<int>graph[n];
    vector<bool>vis(n,false);
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            count++;
            solve(edge,vis,i);
        }
    }
    return count-1;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>edge[n];
    for(int i = 0; i < e;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cout<<get_ans(edge,n,e);
    return 0;
}