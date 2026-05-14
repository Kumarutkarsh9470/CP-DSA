#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<bool> inS(n + 3, false);
    int distinct_initial = 0;

    // Read array and find unique elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!inS[a[i]]) {
            inS[a[i]] = true;
            distinct_initial++;
        }
    }

    // P[x] is 1 if both x and x+2 are present in the array A
    vector<int> P(n + 3, 0);
    for (int i = 1; i <= n; ++i) {
        if (inS[i] && inS[i + 2]) {
            P[i] = 1;
        }
    }
    vector<int> V(n + 3, 0);
    for (int i = 1; i <= n; ++i) {
        V[i] = P[i] + P[i - 1];
    }
    vector<int> sufV(n + 3, 0);
    sufV[n] = V[n];
    for (int i = n - 1; i >= 1; --i) {
        sufV[i] = max(V[i], sufV[i + 1]);
    }
    for (int L = 1; L <= n; ++L) {
        int max_k = P[L];
        if (L < n) {
            max_k = max(max_k, sufV[L + 1]);
        }
        
        // The answer is initial distinct elements minus the maximum merges we can force
        cout << distinct_initial - max_k << (L == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}