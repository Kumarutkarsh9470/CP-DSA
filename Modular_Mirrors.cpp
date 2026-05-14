#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
void solve() {
    ll n,m;
    cin >> n >> m;
    if (m == 1 || (n + 1) % 3 != 0) {
        cout << -1 <<endl;
        return;
    }
    for (ll i = 1; i <= n; ++i) {
        ll mod_val = i % 6;
        if (mod_val == 1 || mod_val == 2) {
            cout << 1 << (i == n ? "" : " ");
        } else if (mod_val == 4 || mod_val == 5) {
            cout << m - 1 << (i == n ? "" : " ");
        } else {
            cout << 0 << (i == n ? "" : " ");
        }
    }
    cout<<endl;
}
int main() {
    ll t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}