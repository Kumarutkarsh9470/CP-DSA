#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    int K = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1' && (i == 0 || S[i - 1] == '0')) {
            K++;
        }
    }
    if (K == 0) {
        cout << string(N, '0') << "\n";
        return;
    }
    int suffixLen = (S.back() == '1') ? (2 * K - 1) : (2 * K);
    int leadingZeros = N - suffixLen;

    string ans = "";
    ans.append(leadingZeros, '0'); 
    for (int i = 0; i < K; i++) {
        ans += '1';
        if (i != K - 1 || S.back() == '0') {
            ans += '0';
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}