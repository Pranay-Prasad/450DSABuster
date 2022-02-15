// Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }
    int bad = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
        {
            bad++;
        }
    }
    int ans = bad;
    int i = 0, j = count;
    while (j < n)
    {
        if (arr[i] > k)
        {
            bad--;
        }
        if (arr[j] > k)
        {
            bad++;
        }
        i++, j++;
        ans = min(ans, bad);
    }
    cout<<ans<<endl;
    return 0;
}