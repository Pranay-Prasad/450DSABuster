#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+3,inf = 1e9;
int cost = 0;
vector<pair<int,int>>adj[N];
vector<int>dist(N),parent(N);
vector<bool>vis(N,false);
void primsMST(int src,int n){
    for(int i = 0; i < n;i++){
        dist[i] = inf;
    }
    set<vector<int>>s;
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += w;
        for(auto p : adj[x[1]]){
            if(!vis[p.first]) continue;
            if(dist[p.first] > p.second){
                s.erase({dist[p.first],p.first});
                dist[p.first] = p.second;
                s.insert({dist[p.first],p.first});
                parent[p.first] = x[1];
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    primsMST(0,n);
    cout<<cost<<endl;
    return 0;
}