//Dijkstra Algo to find hortest path
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e8;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>graph[n+1];
    for(int i =0;i < m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        // {x,y} = edge , w = weight of edge
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    int src;
    cin>>src;
    vector<int>dist(n+1,inf); //distance vector
    dist[src] = 0;
    set<pair<int,int>>s;
    s.insert({0,src});
    //{weight,node}
    while(!s.empty()){
        auto x = *s.begin();
        s.erase(x);
        for(auto i:graph[x.second]){
            if(dist[i.first] > dist[x.second]+i.second){
                s.erase({dist[i.first],i.first});
                dist[i.first] = dist[x.second]+i.second;
                s.insert({dist[i.first],i.first});
            }
        }
    }
    for(int i = 1; i <= n;i++){
        cout<<((dist[i] < inf)?dist[i]:-1)<<"\n";
    }
    return 0;
}      