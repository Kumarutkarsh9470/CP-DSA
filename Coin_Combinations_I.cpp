#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> c;
    for(ll j=0;j<n;j++){
        ll input;
        cin>>input;
        c.push_back(input);
    }
    vector<ll> dp(x+1,0); // dp[i]=number of ways to form sum i
    dp[0]=1;
    for(ll j=1;j<=x;j++){
        for(auto coin:c){
            if(j-coin>=0){
                dp[j]=(dp[j]+dp[j-coin])%MOD;
            }
        }
    }
    cout<<dp[x]%MOD<<endl;
    return 0;
}