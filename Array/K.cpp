// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.
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
    vi vec(n);
    For(i,n) cin>>vec[i];
    // using tortoise and hare 
    int slow = vec[0],fast = vec[0];
    do{
        slow = vec[slow];
        fast = vec[vec[fast]];
    }while( slow != fast);
    slow = vec[0];
    while(slow != fast){
        slow = vec[slow];
        fast = vec[fast];
    }
    cout<<fast<<endl;
    return 0;
}