// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.
#include<bits/stdc++.h>
using namespace std;
bool ok(int x,int y,int n,vector<vector<int>>&m,vector<vector<bool>>&vis){
    if((x >=0 && x < n) && (y >= 0 && y < n) && vis[x][y] == false && m[x][y] == 1){
        return true;
    }
    return false;
}
void solve(vector<vector<int>>&m,int n,vector<string>&ans,int x,int y,vector<vector<bool>>&vis,string res){
    if(x == n-1 && y == n-1){
        ans.push_back(res);
        return;
    }
    vis[x][y] = true;
    if(ok(x+1,y,n,m,vis)){
        res.push_back('D');
        solve(m,n,ans,x+1,y,vis,res);
        res.pop_back();
    }
    if(ok(x-1,y,n,m,vis)){
        res.push_back('U');
        solve(m,n,ans,x-1,y,vis,res);
        res.pop_back();
    }
    if(ok(x,y+1,n,m,vis)){
        res.push_back('R');
        solve(m,n,ans,x,y+1,vis,res);
        res.pop_back();
    }
    if(ok(x,y-1,n,m,vis)){
        res.push_back('L');
        solve(m,n,ans,x,y-1,vis,res);
        res.pop_back();
    }
    vis[x][y] = false;
}
vector<string>get_Path(vector<vector<int>>&m,int n){
    vector<string>ans;
    if(m[0][0] == 0) return ans;
    string res = "";
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    solve(m,n,ans,0,0,vis,res);
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>m(n,vector<int>(n));
    for(int i = 0; i <n;i++){
        for(int j = 0; j<n;j++){
            cin>>m[i][j];
        }
    }
    vector<string>ans = get_Path(m,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}