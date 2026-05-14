#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ll T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        vector<ll> neg;
        ll sum=0,count=0;
        for (ll i=0;i<N;i++) {
            ll x;
            cin>>x;
            if (x>=0) {
                sum+=x;
                count++;
            } else {
                neg.push_back(x);
            }
        }
        sort(neg.rbegin(), neg.rend());
        for (ll x : neg) {
            if (sum + x >= 0) {
                sum += x;
                count++;
            } else {
                break;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}