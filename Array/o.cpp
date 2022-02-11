// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a) for(int i = 0; i < a ;i++)
#define RFor(i,a,b) for(int i = a; i >= b ;i--)
#define vi vector<int>
#define mi map<int,int>
void solve(vector<int>&vec){
    int i = 0;
    for(i = vec.size()-1;i > 0;i--){
        if(vec[i] > vec[i-1])
            break;
    }
    if(i == 0){
        reverse(vec.begin(),vec.end());
    }
    else{
        int x = vec[i-1],s = i;
        for(int j = i+1; j < vec.size();j++){
            if(vec[j] > x && vec[j] <= vec[s]){
                s = j;
            }
        }
        swap(vec[i-1],vec[s]);
        sort(vec.begin()+i,vec.end());
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>vec{1,2,3};
    solve(vec);
    for(auto x:vec){
        cout<<x<<" ";
    }
    return 0;
}