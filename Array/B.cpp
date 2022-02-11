//Maximum and minimum of an array using minimum number of comparisons
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
    int minn = INT_MAX,maxx = INT_MIN;
    for(int i = 0; i < n;i++){
        minn = min(minn,arr[i]);
        maxx = max(maxx,arr[i]);
    }
    cout<<"MIN: "<<minn<<" Max: "<<maxx<<endl;
    //TC = O(n)  SC = O(1);
    return 0;
}