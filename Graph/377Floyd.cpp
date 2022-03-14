#include<bits/stdc++.h>
using namespace std;
const int inf = 1e8; 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(n,inf));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin>>graph[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++){
                if(j == i || k == i) continue;
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}