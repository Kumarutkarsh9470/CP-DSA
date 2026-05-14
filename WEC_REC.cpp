#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, x, k;
        cin >> n >> x >> k;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<ll>());
        vector<ll> clusters;
        ll cnt = 1;
        for(ll i = 1; i < n; i++) {
            if(a[i] == a[i-1]) {
                cnt++;
            }
            else {
                clusters.push_back(cnt);
                cnt = 1;
            }
        }
        clusters.push_back(cnt);
        ll eligible = 0;
        for(ll i = 0; i < min(k, (ll)clusters.size()); i++) {
            eligible += clusters[i];
        }
        cout << min(eligible, x) << endl;
    }
    return 0;
}