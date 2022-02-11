// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
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
    vector<vector<int>>intervals;
    for(int i = 0; i < n;i++){
        int s,e;
        cin>>s>>e;
        intervals.push_back({s,e});
    }
    vector<vector<int>>ans;
    vector<pair<int,int>>vec;
    for(int i = 0; i < intervals.size();i++){
        vec.push_back({intervals[i][0],intervals[i][1]});
    }
    sort(vec.begin(),vec.end());
    int start = vec[0].first;
    int end = vec[0].second;
    for(int i = 1; i < vec.size();i++){
        if(vec[i].first > end){
            ans.push_back({start,end});
            start = vec[i].first;
            end = max(end,vec[i].second);
        }
        else if(vec[i].first <= end){
            end = max(end,vec[i].second);
        }
    }
    ans.push_back({start,end});
    for(auto x:ans){
        cout<<"["<<x[0]<<","<<x[1]<<"]"<<endl;
    }
    return 0;
}