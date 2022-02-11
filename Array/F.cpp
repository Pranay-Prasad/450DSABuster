// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.
// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in the union.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
    cin>>m;
    int brr[m];
    for(int i = 0; i < m;i++){
        cin>>brr[i];
    }
    map<int,int>mp;
    for(int i = 0; i < n;i++) mp[arr[i]]++;
    for(int i = 0; i < m;i++) mp[brr[i]]++;
    cout<<mp.size()<<endl;
    return 0;
}