#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1,LLONG_MAX);
    dp[n]=0;
    for(ll i=n;i>=0;i--){
        if(dp[i]==LLONG_MAX) continue;
        vector<ll> digits;
        ll temp=i;
        while(temp>0){
            digits.push_back(temp%10);
            temp/=10;
        }
        for(auto d:digits){
            if(d==0) continue;
            if(i-d>=0){
                dp[i-d]=min(dp[i-d],dp[i]+1);
            }
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}