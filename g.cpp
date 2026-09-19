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
    for (auto &x : f) cin >> x;

    ll s, t;
    cin >> s >> t;

    /* create two segment trees:

        inTree:
            child -> parent
        Used for:
            [L,R] -> Y

        outTree:
            parent -> child
        Used for:
            X -> [L,R]
    */

    
    int MAXNODES = 9 * n + 10;

    vector<vector<Edge>> g(MAXNODES);

    int nxt = n;

    vector<int> inTree(4 * n);
    vector<int> outTree(4 * n);

    auto addEdge = [&](int u, int v, ll w) {
        g[u].push_back({v, w});
    };

   
    // compressor tree: child -> parent
    // Original frequency -> leaf
    auto buildIn = [&](auto&& self, int p, int l, int r) -> void {
        inTree[p] = nxt++;

        if (l == r) {
            addEdge(l, inTree[p], 0);
            return;
        }

        int mid = (l + r) / 2;

        self(self, p * 2, l, mid);
        self(self, p * 2 + 1, mid + 1, r);

        addEdge(inTree[p * 2], inTree[p], 0);
        addEdge(inTree[p * 2 + 1], inTree[p], 0);
    };

    
    // expander tree: parent -> child
    // Leaf -> original frequency
    auto buildOut = [&](auto&& self, int p, int l, int r) -> void {
        outTree[p] = nxt++;

        if (l == r) {
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


    // connect adjacent frequencies
    for (int i = 0; i + 1 < n; i++) {
        ll cost = f[i + 1] - f[i];

        addEdge(i, i + 1, cost);
        addEdge(i + 1, i, cost);
    }

    // Add edges from a segment tree range to a node.
    auto addRangeToPoint =
        [&](auto&& self, int p, int l, int r,
            int ql, int qr, int target, ll cost) -> void {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            addEdge(inTree[p], target, cost);
            return;
        }

        int mid = (l + r) / 2;

        self(self, p * 2, l, mid,
             ql, qr, target, cost);

        self(self, p * 2 + 1, mid + 1, r,
             ql, qr, target, cost);
    };

    // Add edges from one node to a segment-tree range.
    auto addPointToRange =
        [&](auto&& self, int p, int l, int r,
            int ql, int qr, int source, ll cost) -> void {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            addEdge(source, outTree[p], cost);
            return;
        }

        int mid = (l + r) / 2;

        self(self, p * 2, l, mid,
             ql, qr, source, cost);

        self(self, p * 2 + 1, mid + 1, r,
             ql, qr, source, cost);
    };


    auto getIndex = [&](ll x) {
        return int(lower_bound(f.begin(), f.end(), x) - f.begin());
    };


    
    for (int q = 0; q < m; q++) {
        int type;
        ll a, L, R, C;

        cin >> type >> a >> L >> R >> C;

        // Stable frequencies inside [L,R]
        int left =
            lower_bound(f.begin(), f.end(), L) - f.begin();

        int right =
            upper_bound(f.begin(), f.end(), R) - f.begin() - 1;


        if (left > right)
            continue;

        if (type == 0) {

            ll realL = a;
            ll realR = L;
            ll Y = R;

            left =
                lower_bound(f.begin(), f.end(), realL) - f.begin();

            right =
                upper_bound(f.begin(), f.end(), realR) - f.begin() - 1;

            if (left > right)
                continue;

            int y = getIndex(Y);

            addRangeToPoint(
                addRangeToPoint,
                1, 0, n - 1,
                left, right,
                y, C
            );
        }
        else {

            ll X = a;

            int x = getIndex(X);

            addPointToRange(
                addPointToRange,
                1, 0, n - 1,
                left, right,
                x, C
            );
        }
    }

    int start = getIndex(s);
    int target = getIndex(t);


    // Dijkstra
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

        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[target] << '\n';

    return 0;
}