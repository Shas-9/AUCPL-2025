#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using vi = vector<int>;
using vll = vector<long long>;

constexpr int INF = 1e9+7;
constexpr ll LINF = 1e18;

int n;
vector<vi> children;
ll res;

int dfs(int u) {
    int free_vertices = 0;
    for (int v : children[u]) free_vertices += dfs(v);
    res += free_vertices / 2;
    return (free_vertices % 2) + 1;
}

void solve() {
    int t;
    if (!(cin >> t)) return;
    while (t--) {
        cin >> n;
        children.assign(n + 1, vi());
        for (int i = 2; i <= n; i++) {
            int p; cin >> p;
            children[p].pb(i);
        }
        res = 0;
        dfs(1);
        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    while(tc--) {
        solve();
    }

    return 0;
}
