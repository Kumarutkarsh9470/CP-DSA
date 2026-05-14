#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool validOddPos(char c){
    return (c == 'u' || c == 'o');
}
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        string s;
        cin >> n >> s;
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll len = 0;
            for (ll j = i; j < n; j++) {
                ll pos = j - i + 1; 
                bool ok = false;
                if (pos % 2 == 1) {
                    ok = validOddPos(s[j]);
                } else {
                    ok = (s[j] == 'w');
                }
                if (!ok) break;
                len++;
                if (len % 2 == 1) {
                    ans = max(ans, len);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}