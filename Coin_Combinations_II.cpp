#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
    for(auto coin:c){
        for(ll j=1;j<=x;j++){
            if(j-coin>=0){
                dp[j]+=dp[j-coin];
                dp[j]%=1000000007;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}