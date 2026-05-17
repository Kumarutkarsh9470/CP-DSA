#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> h;
    vector<ll> s;
    for(ll j=0;j<n;j++){
        ll input;
        cin>>input;
        h.push_back(input);
    }
    for(ll j=0;j<n;j++){
        ll input;
        cin>>input;
        s.push_back(input);
    }
    vector<ll> dp(x+1,0); // dp[i]=maximum pages with cost i
    dp[0]=0;
    for(ll i=0;i<n;i++){
        for(ll j=x;j>=h[i];j--){
            dp[j]=max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}