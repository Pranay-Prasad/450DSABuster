// Given a grid of size n*m (n is number of rows and m is number of columns grid has) consisting of '0's(Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
    {
        return;
    }
    if (!vis[i][j])
    {
        vis[i][j] = true;
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i, j - 1);
        dfs(grid, vis, i + 1, j + 1);
        dfs(grid, vis, i - 1, j - 1);
        dfs(grid, vis, i + 1, j - 1);
        dfs(grid, vis, i - 1, j + 1);
    }
}
int solve(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                dfs(grid, vis, i, j);
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << solve(grid) << endl;
    return 0;
}