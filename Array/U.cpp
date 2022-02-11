// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>&vec,int n){
    set<int>s;
    int sum = 0;
    for(int i = 0; i < n;i++){
        sum += vec[i];
        if(s.count(sum) || sum == 0 || vec[i] == 0){
            return true;
        }
        s.insert(sum);
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n;i++){
        cin>>vec[i];
    }
    bool ans = solve(vec,n);
    (ans)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}