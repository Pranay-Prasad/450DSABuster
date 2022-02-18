//BFS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>graph[n+1];
    for(int i = 0; i < e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool>vis(n+1,false);
    vector<int>ans;
    queue<int>q;
    vis[1] = true;
    q.push(1);
    while(!q.empty()){
        cout<<"YES"<<endl;
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto x:graph[node]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
            }
        }
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}