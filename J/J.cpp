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
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    
    vector<ll> dirt(m, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == 'D') dirt[j]++;
    
    ll total_dirt = 0;
    for(int j = 0; j < m; j++) total_dirt += dirt[j];
    

    vector<ll> P(m+1, 0);
    for(int j = 0; j < m; j++) P[j+1] = P[j] + dirt[j];
    
    ll ans = LLONG_MAX;
    ll min_val = 0;
    
    for(int r = 0; r < m; r++){
        ll lval = -(ll)n * r + 2 * P[r];
        min_val = min(min_val, lval);
        
        ll cost = (ll)n * r - 2 * P[r+1] + n + total_dirt + min_val;
        ans = min(ans, cost);
    }
    
    cout << ans * 1000 << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}