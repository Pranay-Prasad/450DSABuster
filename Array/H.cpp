// Kanades Algo maximum sum subarray
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
    int maxx = INT_MIN,sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
        maxx = max(maxx,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    if(maxx < 0){
        cout<<maxx<<endl;
    }
    else{
        cout<<max(maxx,sum)<<endl;
    }
    return 0;
}