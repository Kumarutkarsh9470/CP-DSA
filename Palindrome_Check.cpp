#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> a(n);
        for (ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll l=0,r=n-1;
        bool possible = true;
        while(l<r){
            if (a[l] == a[r]) {
                l++;
                r--;
            }
            else if (a[l] == k) {
                l++;
            }
            else if (a[r] == k) {
                r--;
            }
            else {
                possible = false;
                break;
            }
        }
        cout<<(possible?"Yes":"No")<<endl;
    }

    return 0;
}