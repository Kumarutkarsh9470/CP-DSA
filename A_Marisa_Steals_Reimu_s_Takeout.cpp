#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        ll zeroes=0;
        ll ones=0;
        ll twos=0;
        for(ll j=0;j<n;j++){
            ll input;
            cin>>input;
if(input==0){
                zeroes++;
            }else if(input==1){
                ones++;
            }else{
                twos++;
            }
        }
        if(ones==0 && twos==0){
            cout<<zeroes<<endl;
            continue;
        }else if(ones==0){
            cout<<zeroes+(twos/3)<<endl;
            continue;
        } else if(twos==0){
            cout<<zeroes+(ones/3)<<endl;
            continue;
        }
        ll ans=min(ones,twos);
ll left=abs(ones-twos);
        ans+=(left/3);
cout<<zeroes+ans<<endl;
    }
    return 0;
}