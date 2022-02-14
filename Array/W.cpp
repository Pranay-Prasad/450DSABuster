// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&vec,int n){
    int ans = LONG_LONG_MIN;
    int maxx = 1,minn = 1;
    for(int i = 0; i < n;i++){
        if(vec[i] == 0){
            maxx = 1,minn = 1;
            continue;
        }
        int tmp = maxx*vec[i];
        maxx = max(maxx*vec[i],max(minn*vec[i],vec[i]));
        minn = min(tmp,min(minn*vec[i],vec[i]));
        ans = max(ans,maxx);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n;i++){
        cin>>vec[i];
    }
    cout<<solve(vec,n)<<endl;
    return 0;
}