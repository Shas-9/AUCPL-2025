#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = (1LL << 62);

struct Edge {
    int to;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> f(n);
    for (ll &x : f)
        cin >> x;

    ll s, t;
    cin >> s >> t;

    /*
        Original frequency nodes:
            0 ... n-1

        We build two segment trees.

        inTree:
            child -> parent
        Used for:
            range -> point

        outTree:
            parent -> child
        Used for:
            point -> range
    */

    int maxNodes = 5 * n + 10;
    vector<vector<Edge>> g(maxNodes);

    int nxt = n;

    vector<int> inTree(4 * n);
    vector<int> outTree(4 * n);

    auto addEdge = [&](int u, int v, ll w) {
        g[u].push_back({v, w});
    };

    // ------------------------------------------------------------
    // Segment tree for RANGE -> POINT
    // Edges go child -> parent.
    // ------------------------------------------------------------
    auto buildIn = [&](auto &&self, int p, int l, int r) -> void {
        inTree[p] = nxt++;

        if (l == r) {
            // Original frequency can enter its segment-tree leaf.
            addEdge(l, inTree[p], 0);
            return;
        }

        int mid = (l + r) / 2;

        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        addEdge(inTree[p * 2], inTree[p], 0);
        addEdge(inTree[p * 2 + 1], inTree[p], 0);
    };

    // ------------------------------------------------------------
    // Segment tree for POINT -> RANGE
    // Edges go parent -> child.
    // ------------------------------------------------------------
    auto buildOut = [&](auto &&self, int p, int l, int r) -> void {
        outTree[p] = nxt++;

        if (l == r) {
            // Segment-tree leaf can exit to the real frequency.
            addEdge(outTree[p], l, 0);
            return;
        }

        int mid = (l + r) / 2;

        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        addEdge(outTree[p], outTree[p * 2], 0);
        addEdge(outTree[p], outTree[p * 2 + 1], 0);
    };

    buildIn(buildIn, 1, 0, n - 1);
    buildOut(buildOut, 1, 0, n - 1);

    // ------------------------------------------------------------
    // Manual recalibration.
    //
    // Only adjacent frequencies are necessary because:
    //
    // (f[i+1]-f[i]) + ... + (f[j]-f[j-1])
    // = f[j]-f[i]
    // ------------------------------------------------------------

    for (int i = 0; i + 1 < n; ++i) {
        ll w = f[i + 1] - f[i];

        addEdge(i, i + 1, w);
        addEdge(i + 1, i, w);
    }

    // ------------------------------------------------------------
    // Add:
    //
    //      every point in [ql,qr] -> target
    //
    // using O(log n) edges.
    // ------------------------------------------------------------

    auto rangeToPoint =
        [&](auto &&self,
            int p, int l, int r,
            int ql, int qr,
            int target, ll cost) -> void {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            addEdge(inTree[p], target, cost);
            return;
        }

        int mid = (l + r) / 2;

        self(self,
             p * 2, l, mid,
             ql, qr,
             target, cost);

        self(self,
             p * 2 + 1, mid + 1, r,
             ql, qr,
             target, cost);
    };

    // ------------------------------------------------------------
    // Add:
    //
    //      source -> every point in [ql,qr]
    //
    // using O(log n) edges.
    // ------------------------------------------------------------

    auto pointToRange =
        [&](auto &&self,
            int p, int l, int r,
            int ql, int qr,
            int source, ll cost) -> void {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            addEdge(source, outTree[p], cost);
            return;
        }

        int mid = (l + r) / 2;

        self(self,
             p * 2, l, mid,
             ql, qr,
             source, cost);

        self(self,
             p * 2 + 1, mid + 1, r,
             ql, qr,
             source, cost);
    };

    auto getIndex = [&](ll x) -> int {
        return lower_bound(f.begin(), f.end(), x) - f.begin();
    };

    // ------------------------------------------------------------
    // Read modules
    // ------------------------------------------------------------

    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;

        if (type == 0) {
            /*
                Compressor:

                    0 L R Y C

                Any stable frequency in [L,R]
                can go to Y for cost C.
            */

            ll L, R, Y, C;
            cin >> L >> R >> Y >> C;

            int ql =
                lower_bound(f.begin(), f.end(), L)
                - f.begin();

            int qr =
                upper_bound(f.begin(), f.end(), R)
                - f.begin() - 1;

            if (ql > qr)
                continue;

            int y = getIndex(Y);

            rangeToPoint(
                rangeToPoint,
                1, 0, n - 1,
                ql, qr,
                y, C
            );
        }
        else {
            /*
                Expander:

                    1 X L R C

                X can go to any stable frequency
                in [L,R] for cost C.
            */

            ll X, L, R, C;
            cin >> X >> L >> R >> C;

            int ql =
                lower_bound(f.begin(), f.end(), L)
                - f.begin();

            int qr =
                upper_bound(f.begin(), f.end(), R)
                - f.begin() - 1;

            if (ql > qr)
                continue;

            int x = getIndex(X);

            pointToRange(
                pointToRange,
                1, 0, n - 1,
                ql, qr,
                x, C
            );
        }
    }

    // ------------------------------------------------------------
    // Dijkstra
    // ------------------------------------------------------------

    int start = getIndex(s);
    int target = getIndex(t);

    vector<ll> dist(nxt, INF);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        if (u == target)
            break;

        for (const Edge &e : g[u]) {
            if (dist[e.to] > d + e.w) {
                dist[e.to] = d + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    cout << dist[target] << '\n';

    return 0;
}