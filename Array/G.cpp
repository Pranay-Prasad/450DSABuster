//Given an array, rotate the array by one position in clock-wise direction.
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
    int arr[n];
    For(i,n) cin>>arr[i];
    int last = arr[n-1];
    for(int i = n-1;i > 0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last;
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}