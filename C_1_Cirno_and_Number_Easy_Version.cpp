#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dfs(ll idx,ll current_val,ll state,ll l,const string& a_str,const vector<char>& d,ll a,ll& min_diff){
    if(idx==l){
        ll diff=abs(a-current_val);
        if(min_diff==-1 || diff<min_diff) {
            min_diff=diff;
        }
        return;
    }
    ll current_digit=a_str[idx] - '0';
    for (char c:d) {
        ll val=c-'0';
        if(state==1){
            if(c==d[1]) {
                dfs(idx+1,current_val*10+val,1,l,a_str,d,a,min_diff);
            }
        } 
        else if(state==2){
            if(c==d[0]) {
                dfs(idx+1,current_val*10+val,2,l,a_str,d,a,min_diff);
            }
        } 
        else {
            if(val<current_digit){
                dfs(idx+1,current_val*10+val,1,l,a_str,d,a,min_diff); 
            }else if (val>current_digit){
                dfs(idx+1,current_val*10+val,2,l,a_str,d,a,min_diff); 
            }else{
                dfs(idx+1,current_val*10+val,0,l,a_str,d,a,min_diff);
            }
        }
    }
}
void solve(){
    ll a,n;
    cin>>a>>n;
    vector<char> d(n);
    for(ll j=0;j<n;j++) {
        cin>>d[j];
    }
    sort(d.begin(),d.end());
    string a_str=to_string(a);
    ll l=a_str.length();
    ll min_diff = -1;
    if(l>1){
        string cand_smaller="";
        for (ll i=0;i<l-1;i++) cand_smaller+=d[1];
        ll val=stoll(cand_smaller);
        ll diff=abs(a-val);
        if(min_diff==-1 || diff<min_diff) min_diff=diff;
    }
    string cand_larger = "";
    if(d[0]=='0') {
        cand_larger+=d[1];
        for(ll i=0;i<l;i++) cand_larger+=d[0];
    } else {
        for (ll i=0;i<l+1;i++) cand_larger+=d[0];
    }
    ll val2=stoll(cand_larger);
    ll diff2=abs(a-val2);
    if(min_diff==-1 || diff2<min_diff) min_diff=diff2;
    dfs(0,0,0,l,a_str,d,a,min_diff);
    cout<<min_diff<<endl;
}
int main() {
    ll t;
    if(cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}