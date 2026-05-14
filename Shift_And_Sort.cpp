#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<ll> x(n, 0); // transfer used at index i
        bool ok = true;

        for (int i = 0; i < n - 1; ++i) {
            if (a[i] <= a[i + 1]) continue;

            // adjacent inversions => impossible
            if (i > 0 && a[i - 1] > a[i]) {
                ok = false;
                break;
            }

            // minimum needed to fix inversion
            ll low = (a[i] - a[i + 1] + 1) / 2;

            ll high = (ll)4e18;
            if (i > 0) {
                if (i >= 2 && a[i - 2] > a[i - 1]) {
                    high = min(high,
                               a[i] - a[i - 1] - x[i - 2]);
                } else {
                    high = min(high,
                               a[i] - a[i - 1]);
                }
            }
            if (i + 2 < n) {
                bool nextForced = false;
                if (i + 2 < n - 1 && a[i + 2] > a[i + 3]) {
                    nextForced = true;
                }

                if (!nextForced) {
                    high = min(high,
                               a[i + 2] - a[i + 1]);
                }
            }

            if (low <= 0 || low > high) {
                ok = false;
                break;
            }

            x[i] = low; 
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}