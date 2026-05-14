#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < q; ++i) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll u, x;
            cin >> u >> x;
            a[u] = x;
        } else if(type==2){
            ll l, r;
            cin >> l >> r;
            ll len = r - l + 1;
            if (len == 1) {
                cout<<a[l]<<endl;
            } else if (len % 2 == 0) {
                ll k = len / 2;
                cout << max(a[l + k - 1], a[l + k]) << "\n";
            } else {
                ll k = len / 2;
                ll m1 = min(a[l + k - 1], a[l + k]);
                ll m2 = min(a[l + k], a[l + k + 1]);
                cout << max(m1, m2) << "\n";
            }
        }
    }
}
int main() {
    ll t;
    if(cin>>t){
        while (t--) {
            solve();
        }
    }
    return 0;
}