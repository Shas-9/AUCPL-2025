#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
}

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long fact[200005], inv_fact[200005];

long long power(long long a, long long b, long long mod){
    long long res = 1; a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}

void precompute(int n){
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[n] = power(fact[n], MOD-2, MOD);
    for(int i = n-1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

long long C(long long n, long long k){
    if(k < 0 || k > n) return 0;
    return fact[n] % MOD * inv_fact[k] % MOD * inv_fact[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    precompute(n);
    vector<vector<int>> children(n+1);
    for(int i = 2; i <= n; i++){ int m; cin >> m; children[m].push_back(i); }
    
    vector<long long> sub(n+1, 0), ans(n+1, 0);
    vector<int> order, stk = {1};
    while(!stk.empty()){ int v = stk.back(); stk.pop_back(); order.push_back(v); for(int c : children[v]) stk.push_back(c); }
    reverse(order.begin(), order.end());
    
    for(int v : order){
        sub[v] = 1;
        for(int c : children[v]) sub[v] += sub[c];
        ans[v] = C(sub[v], k);
        for(int c : children[v]) ans[v] = (ans[v] - C(sub[c], k) + MOD) % MOD;
    }
    
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i==n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}