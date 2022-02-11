// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int solve(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == 0)
    {
        return -1;
    }
    int steps = arr[0];
    int max_reach = arr[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            return jumps;
        }
        max_reach = max(max_reach, arr[i] + i);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= max_reach)
            {
                return -1;
            }
            steps = max_reach - i;
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    For(i, n) cin >> arr[i];
    cout << solve(arr, n) << endl;
    return 0;
}