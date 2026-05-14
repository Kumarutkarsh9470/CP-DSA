#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll calc(ll X, ll K, ll H) {
    if (X == 0) return 0;
    if (X == 1) return H;
    int k = 63 - __builtin_clzll(X);
    ll p = 1LL << k;
    if (X == p) return H;
    ll p2 = p << 1;
    return min(H + calc(X - p, K, H), H + (p2 - X) * K);
}

ll solve(ll s, ll t, ll K, ll H) {
    if (s >= t) return (s - t) * K;
    while (s + (s & -s) <= t) {
        s += (s & -s);
    }
    
    if (s == t) return 0;
    ll ans1 = (s + (s & -s) - t) * K;
    ll ans2 = calc(t - s, K, H);
    
    return min(ans1, ans2);
}

void run_case() {
    int N;
    ll K, H;
    cin >> N >> K >> H;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll total_cost = 0;
    for (int i = 0; i < N - 1; i++) {
        total_cost += solve(A[i], A[i+1], K, H);
    }

    cout << total_cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (cin >> T) {
        while (T--) {
            run_case();
        }
    }
    return 0;
}