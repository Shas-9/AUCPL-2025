#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        p[b] = a;
        sz[a] += sz[b];
    }
};

struct Edge {
    int u, v;
    long long w;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        --edges[i].u;
        --edges[i].v;
        edges[i].id = i;
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.w < b.w;
         });

    // 0 = none
    // 1 = some
    // 2 = all
    vector<int> ans(m, 0);

    DSU dsu(n);

    int l = 0;

    while (l < m) {
        int r = l;

        while (r < m && edges[r].w == edges[l].w)
            ++r;

        /*
         * Process all edges [l, r) together.
         *
         * First construct the graph of current DSU components.
         */

        vector<int> candidates;

        // Map DSU roots to temporary graph vertices.
        unordered_map<int, int> mp;
        mp.reserve(2 * (r - l) + 10);

        int vertexCount = 0;

        auto getVertex = [&](int root) -> int {
            auto it = mp.find(root);

            if (it != mp.end())
                return it->second;

            int id = vertexCount++;
            mp[root] = id;
            return id;
        };

        struct TempEdge {
            int a, b;
            int originalId;
        };

        vector<TempEdge> tempEdges;

        for (int i = l; i < r; i++) {
            int ru = dsu.find(edges[i].u);
            int rv = dsu.find(edges[i].v);

            if (ru == rv) {
                // Already connected using strictly cheaper edges.
                ans[edges[i].id] = 0; // none
                continue;
            }

            int a = getVertex(ru);
            int b = getVertex(rv);

            tempEdges.push_back({
                a,
                b,
                edges[i].id
            });

            // Initially every candidate can occur in some MST.
            ans[edges[i].id] = 1;
        }

        /*
         * Find bridges in the temporary graph.
         *
         * We MUST distinguish edges by edge ID because parallel edges
         * can exist after DSU contraction.
         */

        vector<vector<pair<int, int>>> graph(vertexCount);

        for (int i = 0; i < (int)tempEdges.size(); i++) {
            int a = tempEdges[i].a;
            int b = tempEdges[i].b;

            graph[a].push_back({b, i});
            graph[b].push_back({a, i});
        }

        vector<int> tin(vertexCount, -1);
        vector<int> low(vertexCount, -1);

        int timer = 0;

        function<void(int, int)> dfs =
            [&](int u, int parentEdge) {

                tin[u] = low[u] = timer++;

                for (auto [v, edgeId] : graph[u]) {
                    if (edgeId == parentEdge)
                        continue;

                    if (tin[v] != -1) {
                        low[u] = min(low[u], tin[v]);
                    } else {
                        dfs(v, edgeId);

                        low[u] = min(low[u], low[v]);

                        // This temporary edge is a bridge.
                        if (low[v] > tin[u]) {
                            int original =
                                tempEdges[edgeId].originalId;

                            ans[original] = 2; // all
                        }
                    }
                }
            };

        for (int i = 0; i < vertexCount; i++) {
            if (tin[i] == -1)
                dfs(i, -1);
        }

        /*
         * Only NOW merge all components using weight w.
         *
         * We cannot union them before bridge detection, because all
         * equal-weight edges must be considered simultaneously.
         */
        for (int i = l; i < r; i++) {
            dsu.unite(edges[i].u, edges[i].v);
        }

        l = r;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == 0)
            cout << "none\n";
        else if (ans[i] == 1)
            cout << "some\n";
        else
            cout << "all\n";
    }

    return 0;
}