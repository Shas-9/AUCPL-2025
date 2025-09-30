#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i);
#define all(x) begin(x), end(x);
#define sz(x) (int)(x).size();
#define pb push_back;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int INF = 1e9+7;
constexpr ll LINF = 1e18;

void solve() {
    
}

const int MAXN = 10005;
vector<pair<int,int>> adj[MAXN]; 
int tin[MAXN], low[MAXN], timer;
bool isBridge;
int n, m;

void dfs(int v, int p = -1) {
    tin[v] = low[v] = ++timer;
    for (auto [to, id] : adj[v]) {
        if (id == p) continue;
        if (!tin[to]) {
            dfs(to, id);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                // Found a bridge
                isBridge = true;
            }
        } else {
            low[v] = min(low[v], tin[to]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int u, v, t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    for (int i = 1; i <= n; i++) {
        if (!tin[i]) dfs(i);
    }

    if (isBridge) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}