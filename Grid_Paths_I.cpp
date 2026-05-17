#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
int main(){
    ll n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(ll i=0;i<n;i++){
        string row;
        cin>>row;
        for(ll j=0;j<n;j++){
            grid[i][j]=row[j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(grid[i][j]=='*') continue;
            if(i==0){
                if(j==0) dp[i][j]=1;
                else dp[i][j]=dp[i][j-1];
            }else if(j==0){
                if(i==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}