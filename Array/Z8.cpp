// In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0; i < n;i++){
        cin>>vec[i];
    }
    int profit[n];
    memset(profit,0,sizeof(profit));
    int max_val = vec[n-1];
    for(int i = n-2;i >= 0;i--){
        if(vec[i] > max_val){
            max_val = vec[i];
        }
        profit[i] = max(profit[i+1],max_val-vec[i]);
    }
    int min_val = vec[0];
    for(int i = 1; i < n;i++){
        if(vec[i] < min_val){
            min_val = vec[i];
        }
        profit[i] = max(profit[i-1],profit[i] + (vec[i]-min_val));
    }
    cout<<profit[n-1]<<endl;
    return 0;
}