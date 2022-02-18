//Create a graph and print it
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
    for(int i = 0; i<=n;i++){
        cout<<i<<"-> ";
        for(auto x:graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}