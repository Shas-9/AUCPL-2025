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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    unordered_map<string,int> taskIdx;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        taskIdx[s] = i;
    }
    
    vector<int> emp(m);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        int mask = 0;
        for(int j = 0; j < k; j++){
            string s; cin >> s;
            mask |= (1 << taskIdx[s]);
        }
        emp[i] = mask;
    }
    
    int full = (1 << n) - 1;
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;
    
    for(int mask = 0; mask <= full; mask++){
        if(dp[mask] == INT_MAX) continue;
        for(int i = 0; i < m; i++){
            int nmask = mask | emp[i];
            if(dp[nmask] > dp[mask] + 1)
                dp[nmask] = dp[mask] + 1;
        }
    }
    
    cout << dp[full] << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}