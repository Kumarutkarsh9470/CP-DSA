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
    vector<ll> dp(x+1,1e9);
    dp[0]=0;
    for(ll j=1;j<=x;j++){
        for(auto coin:c){
            if(j-coin>=0){
                dp[j]=min(dp[j],dp[j-coin]+1);
            }
        }
    }
    if(dp[x]==1e9){
        cout<<-1<<endl;
    }else{
        cout<<dp[x]<<endl;
    }
    return 0;
}