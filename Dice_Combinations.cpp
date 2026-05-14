#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> dp(n+1,0); // dp[i]=number of ways to form sum i
    dp[0]=1;
    for(ll j=1;j<=n;j++){
        for(ll k=1;k<=6;k++){
            if(j-k>=0){
                dp[j]=(dp[j]+dp[j-k])%1000000007;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}