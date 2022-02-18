//DFS
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>vec[],vector<bool>&vis,int x){
    vis[x] = true;
    cout<<x<<" ";
    for(auto n:vec[x]){
        if(!vis[n]){
            dfs(vec,vis,n);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>vec[n+1];
    for(int i = 0; i < m;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    vector<bool>vis(n+1,false);
    dfs(vec,vis,1);
    return 0;
}