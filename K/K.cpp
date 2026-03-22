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
    vector<int> p, rnk;
    DSU(int n) : p(n), rnk(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rnk[x] < rnk[y]) swap(x, y);
        p[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<long long,long long>> ext(N);
    for (auto& [x, y] : ext) cin >> x >> y;

    map<long long, vector<long long>> obstByRow, obstByCol;
    for (int i = 0; i < M; i++) {
        long long x, y; cin >> x >> y;
        obstByRow[y].push_back(x);
        obstByCol[x].push_back(y);
    }
    for (auto& [k, v] : obstByRow) sort(v.begin(), v.end());
    for (auto& [k, v] : obstByCol) sort(v.begin(), v.end());

    long long bx, by;
    cin >> bx >> by;

    auto obstBlocksH = [&](long long y, long long x1, long long x2) {
        if (x1 > x2) swap(x1, x2);
        auto it = obstByRow.find(y);
        if (it == obstByRow.end()) return false;
        auto& v = it->second;
        auto lo = upper_bound(v.begin(), v.end(), x1);
        return lo != v.end() && *lo < x2;
    };
    auto obstBlocksV = [&](long long x, long long y1, long long y2) {
        if (y1 > y2) swap(y1, y2);
        auto it = obstByCol.find(x);
        if (it == obstByCol.end()) return false;
        auto& v = it->second;
        auto lo = upper_bound(v.begin(), v.end(), y1);
        return lo != v.end() && *lo < y2;
    };

    auto baseBlocksH = [&](long long y, long long x1, long long x2) {
        if (y < by || y > by+2) return false;
        if (x1 > x2) swap(x1, x2);
        return max(x1+1, bx) <= min(x2-1, bx+2);
    };
    auto baseBlocksV = [&](long long x, long long y1, long long y2) {
        if (x < bx || x > bx+2) return false;
        if (y1 > y2) swap(y1, y2);
        return max(y1+1, by) <= min(y2-1, by+2);
    };

    int BASE = N;
    vector<tuple<long long,int,int>> edges;

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            auto [xi, yi] = ext[i];
            auto [xj, yj] = ext[j];
            if (yi == yj) {
                if (!obstBlocksH(yi, xi, xj) && !baseBlocksH(yi, xi, xj))
                    edges.push_back({abs(xi-xj)-1, i, j});
            } else if (xi == xj) {
                if (!obstBlocksV(xi, yi, yj) && !baseBlocksV(xi, yi, yj))
                    edges.push_back({abs(yi-yj)-1, i, j});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        auto [ex, ey] = ext[i];

        if (ey >= by && ey <= by+2) {
            if (ex < bx && !obstBlocksH(ey, ex, bx))
                edges.push_back({bx-ex-1, i, BASE});
            else if (ex > bx+2 && !obstBlocksH(ey, bx+2, ex))
                edges.push_back({ex-bx-3, i, BASE});
        }

        if (ex >= bx && ex <= bx+2) {
            if (ey < by && !obstBlocksV(ex, ey, by))
                edges.push_back({by-ey-1, i, BASE});
            else if (ey > by+2 && !obstBlocksV(ex, ey, by+2))
                edges.push_back({ey-by-3, i, BASE});
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(N+1);
    long long totalCost = 0;
    int used = 0;

    for (auto [cost, u, v] : edges) {
        if (dsu.unite(u, v)) {
            totalCost += cost;
            if (++used == N) break;
        }
    }

    for (int i = 0; i < N; i++) {
        if (dsu.find(i) != dsu.find(BASE)) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << totalCost << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}