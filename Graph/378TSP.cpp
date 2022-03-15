// Traveling salesman problem
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>&graph,int src){
    vector<int>vertex;
    for(int i = 0;i < graph.size();i++){
        if(i != src) vertex.push_back(i);
    }
    int ans = INT_MAX;
    do{
        int curr = 0;
        int k = src;
        for(int i = 0; i < vertex.size();i++){
            curr += graph[k][vertex[i]];
            k = vertex[i];
        }
        curr += graph[k][src];
        ans = min(ans,curr);
    }while(next_permutation(vertex.begin(),vertex.end()));
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin>>graph[i][j];
        }
    }
    int s = 0;
    cout<<solve(graph,s)<<endl;
    return 0;
}