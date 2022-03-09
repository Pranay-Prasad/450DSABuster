// Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.
#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>adj[],vector<int>&ind,int n){
    queue<int>q;
    vector<int>ans(n+1);
    for(int i = 1;i<=n;i++){
        if(ind[i] == 0){
            q.push(i);
            ans[i] = 1;
        }
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int x:adj[curr]){
            ind[x]--;
            if(ind[x] == 0){
                ans[x] = ans[curr]+1;
                q.push(x);
            }
        }
    }
    for(int i = 1; i <= n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>ind(n+1,0);
    for(int i = 0; i < m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        ind[y]++;
    }
    solve(adj,ind,n);
    return 0;
}