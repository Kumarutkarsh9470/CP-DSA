#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        if(n<=3){
            cout<<1<<endl;
            continue;
        }
        ll delta_d=0;
        ll d=abs(x1-x2);
        delta_d=min(d,n-d);
        cout<<k+delta_d<<endl;
    }
    return 0;
}