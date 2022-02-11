// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.
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
    int n;
    cin>>n;
    vi a(n);
    For(i,n) cin>>a[i];
    int m;
    cin>>m;
    vi b(m);
    For(i,m) cin>>b[i];
    vi vec;
    int i = 0,j = 0;
    while(i < n && j <m){
        if(a[i] < b[j]){
            vec.push_back(a[i]);
            i++;
        }
        else{
            vec.push_back(b[j]);
            j++;
        }
    }
    while(i<n){
        vec.push_back(a[i]);
        i++;
    }
    while(j < m){
        vec.push_back(b[j]);
        j++;
    }
    for(auto x:vec){
        cout<<x<<" ";
    }
    return 0;
}