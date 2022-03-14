#include<bits/stdc++.h>
using namespace std;
const int inf = 1e6;
void belmanford(vector<vector<int>>&adj,int src,int n,int m){
    vector<int>dist(n,inf);
    dist[src] = 0;
    for(int i = 0; i < n-1;i++){
        for(auto x:adj){
            if(dist[x[0]] + x[2] < dist[x[1]]){
                dist[x[1]] = dist[x[0]]+x[2];
            }
        }
    }
    bool ok = true;
    for(auto x:adj){
        if(dist[x[0]] + x[2] < dist[x[1]]){
            cout<<"! NEGATIVE CYCLE !"<<endl;
            ok = false;
            break;
        }
    }
    if(ok){
        for(int i = 0; i < n;i++){
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj;
    for(int i = 0; i < m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj.push_back({x,y,w});
    }
    int src;
    cin>>src;
    belmanford(adj,src,n,m);
    return 0;
}