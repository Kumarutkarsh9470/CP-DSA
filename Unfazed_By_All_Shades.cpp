#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int MAXN = 3005;
ll fact[MAXN], invfact[MAXN];
ll stir[MAXN][MAXN];
ll modpow(ll a, ll b){
    ll r=1;
    while(b){
        if(b&1) r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}
ll C(int n, int r){
    if(r<0 || r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}
vector<int> g[MAXN];
int dista[MAXN];
void bfs(int src, int n){
    for(int i=1; i<=n; i++)
        dista[i]=-1;
    queue<int> q;
    q.push(src);
    dista[src]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(size_t i=0; i<g[u].size(); i++){
            int v = g[u][i];
            if(dista[v]==-1){
                dista[v]=dista[u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;
    for(int i=1; i<MAXN; i++)
        fact[i]=fact[i-1]*i%MOD;

    invfact[MAXN-1]=modpow(fact[MAXN-1], MOD-2);
    for(int i=MAXN-2; i>=0; i--)
        invfact[i]=invfact[i+1]*(i+1)%MOD;

    stir[0][0]=1;
    for(int n=1; n<MAXN; n++){
        for(int k=1; k<=n; k++){
            stir[n][k]=(stir[n-1][k-1] + (ll)k*stir[n-1][k])%MOD;
        }
    }

    int T;
    if(!(cin >> T)) return 0;

    while(T--){
        int N, X;
        cin >> N >> X;

        for(int i=1; i<=N; i++) g[i].clear();

        for(int i=0; i<N-1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bfs(1, N);
        int A=1;
        for(int i=1; i<=N; i++) if(dista[i]>dista[A]) A=i;

        bfs(A, N);
        int B=A;
        for(int i=1; i<=N; i++) if(dista[i]>dista[B]) B=i;
        int D = dista[B];
        vector<int> da(dista, dista + N + 1);

        bfs(B, N);
        vector<int> db(dista, dista + N + 1);

        vector<int> centers;
        for(int i=1; i<=N; i++){
            if(da[i]+db[i]==D){
                if(D%2 == 0){
                    if(da[i]==D/2) centers.push_back(i);
                } else {
                    if(da[i]==D/2 || db[i]==D/2) centers.push_back(i);
                }
            }
        }

        vector<int> groups;
        if(D%2 == 0){
            int c = centers[0];
            for(size_t i=0; i<g[c].size(); i++){
                int nxt = g[c][i];
                int cnt = 0;
                queue<tuple<int,int,int> > qq;
                qq.push(make_tuple(nxt, c, 1));
                
                while(!qq.empty()){
                    tuple<int,int,int> curr = qq.front();
                    qq.pop();
                    int u = get<0>(curr);
                    int p = get<1>(curr);
                    int d = get<2>(curr);
                    
                    if(d == D/2) cnt++;
                    
                    for(size_t j=0; j<g[u].size(); j++){
                        int v = g[u][j];
                        if(v == p) continue;
                        qq.push(make_tuple(v, u, d + 1));
                    }
                }
                if(cnt > 0) groups.push_back(cnt);
            }
        } else {
            int cnt1 = 0, cnt2 = 0;
            for(int i = 1; i <= N; i++){
                if(db[i] == D) cnt1++;
                if(da[i] == D) cnt2++; 
            }
            groups.push_back(cnt1);
            groups.push_back(cnt2);
        }

        vector<ll> dp(X+1, 0);
        dp[0] = 1;
        int total_grouped = 0;
        
        for(size_t i=0; i<groups.size(); i++){
            int s = groups[i];
            total_grouped += s;
            vector<ll> ndp(X+1, 0);
            for(int used = 0; used <= X; used++){
                if(dp[used] == 0) continue;
                for(int t = 1; t <= s; t++){
                    if(used + t > X) break;
                    ll ways = C(X - used, t) * fact[t] % MOD * stir[s][t] % MOD;
                    ndp[used + t] = (ndp[used + t] + dp[used] * ways) % MOD;
                }
            }
            dp = ndp;
        }

        ll bad = 0;
        for(int i = 0; i <= X; i++) bad = (bad + dp[i]) % MOD;
        bad = (bad * modpow(X, N - total_grouped)) % MOD;

        ll total = modpow(X, N);
        ll ans = (total - bad + MOD) % MOD; 
        cout << ans << "\n";
    }
    return 0;
}