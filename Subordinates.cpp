#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll maxn=200005;
vector<ll> adj_list[maxn];
vector<ll> subordinates(maxn,0);
void dfs(ll node){
subordinates[node]=0;
for(auto child:adj_list[node]){
    dfs(child);
    subordinates[node]+=subordinates[child]+1;
}
}
int main(){
    ll n;
    cin>>n;
    for(ll j=2;j<=n;j++){
        ll x;
        cin>>x;
        adj_list[x].push_back(j);
    }
dfs(1);
for(ll j=1;j<=n;j++){
    cout<<subordinates[j]<<" ";
}
cout<<endl;

    return 0;
}