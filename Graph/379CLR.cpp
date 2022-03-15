#include<bits/stdc++.h>
using namespace std;
bool solve2(vector<vector<bool>>&graph,int c,int col[],int v){
    if(v == graph.size()) return true;
    for(int i = 1; i <= c;i++){
        bool check = true;
        for(int i = 0;i < graph.size();i++){
            if(graph[v][i] && c == col[i]){
                check =  false;
                break;
            } 
        }
        // cout<<"yes"<<endl;
        if(check){
            col[v] = i;
            if(solve2(graph,c,col,i+1)) return true;
            col[v] = 0;
        }
    }
    return false;
}
void solve(vector<vector<bool>>&graph,int c){
    int color[graph.size()];
    memset(color,0,sizeof(color));
    if(solve2(graph,c,color,0) == false){
        cout<<"NOT POSSIBLE"<<endl;
        return;
    }
    
    for(int i = 0; i < graph.size();i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<bool>>graph(n,vector<bool>(n,0));
    for(int i = 0; i < m;i++){
        int x,y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int x = 3;
    solve(graph,x);
    return 0;
}