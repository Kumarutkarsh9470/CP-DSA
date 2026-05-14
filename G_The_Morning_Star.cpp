#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll t;
    cin>>t;
for(ll i=0;i<t;i++){
    ll n;
    cin>>n;
    map<ll,ll> x;
    map<ll,ll> y;
    map<ll,ll> one;
    map<ll,ll> minus_one;
    for(ll j=0;j<n;j++){
        ll a,b;
        cin>>a>>b;
        x[a]++;
        y[b]++;
        one[b-a]++;
        minus_one[a+b]++;
    }
    ll ans=0;
    for(auto it:x){
        ans+=it.second*(it.second-1);
    }
    for(auto it:y){
        ans+=it.second*(it.second-1);
    }
    for(auto it:one){
        ans+=it.second*(it.second-1);
    }
    for(auto it:minus_one){
        ans+=it.second*(it.second-1);
    }
    cout<<ans<<endl;
}
    return 0;
}