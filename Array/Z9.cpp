// Given two sorted arrays arr[] of size N and brr[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int brr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    int i = n - 1;
    int j = 0;
    while (i >= 0 && j < m)
    {
        if (arr[i] >= brr[j])
        {
            swap(arr[i], brr[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr, arr + n);
    sort(brr, brr + m);
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
    for(int i = 0; i < m;i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    return 0;
}