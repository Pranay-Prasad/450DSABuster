#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int n, int k)
{
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[k - arr[i]])
        {
            ans += mp[k - arr[i]];
        }
        mp[arr[i]]++;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n, k) << endl;
    return 0;
}