//Dijsktra ago
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e8; 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i = 0; i < m;i++){
        int x,y,e;
        cin>>x>>y>>e;
        adj[x].push_back({y,e});
        adj[y].push_back({x,e});
    }
    int src;
    cin>>src;
    vector<int>dist(n+1,inf);
    dist[src] = 0;
    set<pair<int,int>>s;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *s.begin();
        s.erase(x);
        for(auto i:adj[x.second]){
            if(dist[i.first] > dist[x.second]+i.second){
                s.erase({dist[i.first],i.first});
                dist[i.first] = dist[x.second]+i.second;
                s.insert({dist[i.first],i.first});
            }
        }
    }
    for(int i = 1; i<=n;i++)
    {
        if(dist[i] < inf)
            cout<<dist[i]<<" ";
        else
            cout<<-1<<" ";
    }
    return 0;
}