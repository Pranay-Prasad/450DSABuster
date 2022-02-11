// You dont need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.
#include<bits/stdc++.h>
using namespace std;
vector<int>solve(int n){
    vector<int>ans = {1};
    for(int i = 2; i <= n;i++){
        int carry = 0;
        for(int j = 0 ; j < ans.size();j++){
            int data = ans[j]*i + carry;
            ans[j] = data%10;
            carry = data/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>ans = solve(n);
    for(auto x:ans){
        cout<<x;
    }
    return 0;
}