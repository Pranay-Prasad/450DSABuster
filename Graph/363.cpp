// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.
#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>&image,vector<vector<bool>>&vis,int x,int y,int old,int newColor){
    if(x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) return;
    if(vis[x][y] || image[x][y] != old) return;
    vis[x][y] = true;
    image[x][y] = newColor;
    solve(image,vis,x+1,y,old,newColor);
    solve(image,vis,x-1,y,old,newColor);
    solve(image,vis,x,y+1,old,newColor);
    solve(image,vis,x,y-1,old,newColor);
}
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
    int old = image[sr][sc];
    vector<vector<bool>>vis(image.size(),vector<bool>(image[0].size(),false));
    solve(image,vis,sr,sc,old,newColor);
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n,vector<int>(m));
    for(int i = 0; i < n;i++){
        for(int j = 0; j <m;j++){
            cin>>vec[i][j];
        }
    }
    floodFill(vec,1,1,2);
    for(int i = 0; i < n;i++){
        for(int j = 0; j <m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}