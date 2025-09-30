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

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> p, sz;
    DSU(int n) {
        p.resize(n);
        sz.assign(n,1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        edges.push_back({0, i, a[i]});
    }
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n+1);
    long long total = 0;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
        }
    }

    cout << total << "\n";
    return 0;
}