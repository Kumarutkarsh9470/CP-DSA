#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ll=long long;
int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n);
        for(ll j=0;j<n;j++){
            cin>>v[j].first>>v[j].second;
        }
        sort(v.begin(), v.end());
        ll ans=0;
        Oset s;
        for(ll j=0;j<n;j++){
            ans+=j-s.order_of_key(v[j].second);
            s.insert(v[j].second);
        }
        cout<<ans<<endl;
    }
    return 0;
}