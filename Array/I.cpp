// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer.
// Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, a) for (int i = 0; i < a; i++)
#define RFor(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define mi map<int, int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int arr[n];
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int s = arr[0] + k;
    int l = arr[n - 1] - k;
    for (int i = 0; i < n - 1; i++)
    {
        int mn = min(s, arr[i + 1] - k);
        int mx = max(l, arr[i] + k);
        if (mn < 0)
            continue;
        ans = min(ans, mx - mn);
    }
    cout<<ans<<endl;
    return 0;
}