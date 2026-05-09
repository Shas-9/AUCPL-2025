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

struct DSU {
    int n;
    vector<int> parent, parity;
    vector<ll> offset;
    vector<bool> fixed;
    vector<ll> value;

    DSU(int n) : n(n), parent(n+1), parity(n+1, 1),
                 offset(n+1, 0), fixed(n+1, false), value(n+1, 0) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    pair<int, pair<int, ll>> find(int x) {
        if (parent[x] == x) return {x, {1, 0}};

        auto [root, info] = find(parent[x]);
        int parent_parity = info.first;
        ll parent_offset = info.second;

        int new_parity = parity[x] * parent_parity;
        ll new_offset = parity[x] * parent_offset + offset[x];

        parent[x] = root;
        parity[x] = new_parity;
        offset[x] = new_offset;

        return {root, {new_parity, new_offset}};
    }


    bool unite(int u, int v, ll w, int t) {
        int a = (t == 1 ? 1 : -1);
        ll b = w;

        auto [ru, info_u] = find(u);
        auto [rv, info_v] = find(v);

        int su = info_u.first, sv = info_v.first;
        ll du = info_u.second, dv = info_v.second;

        // case 1: same component
        if (ru == rv) {

            
            int coeff = su - a * sv;
            ll rhs = a * dv + b - du;

            if (coeff == 0) {
                return (rhs == 0);
            } else {
                if (rhs % coeff != 0) return false;

                ll x = rhs / coeff;

                if (fixed[ru] && value[ru] != x) return false;
                fixed[ru] = true;
                value[ru] = x;
            }
            return true;
        }

        // case 2: merge ru under rv
        int k = (a * sv) / su;

        ll rhs = a * dv + b - du;
        if (rhs % su != 0) return false;
        ll c = rhs / su;

        parent[ru] = rv;
        parity[ru] = k;
        offset[ru] = c;

        if (fixed[ru] && fixed[rv]) {
            if (value[ru] != k * value[rv] + c) return false;
        } else if (fixed[ru]) {
            // value[ru] = k * value[rv] + c
            if ((value[ru] - c) % k != 0) return false;
            value[rv] = (value[ru] - c) / k;
            fixed[rv] = true;
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v, t;
        ll w;
        cin >> u >> v >> w >> t;

        if (!dsu.unite(u, v, w, t)) {
            cout << "contradiction\n";
            return 0;
        }
    }

    vector<ll> result(n+1);

    // final values
    for (int i = 1; i <= n; i++) {
        auto [root, info] = dsu.find(i);
        int s = info.first;
        ll d = info.second;

        if (!dsu.fixed[root]) {
            cout << "insufficient\n";
            return 0;
        }

        result[i] = s * dsu.value[root] + d;
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << (i < n ? ' ' : '\n');
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}