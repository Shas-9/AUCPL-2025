#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Edge {
    int u, v;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        graph[u].push_back(v);
    }

    const ll NEG_INF = LLONG_MIN / 4;

    vector<ll> dist(n + 1, NEG_INF);
    dist[1] = 0;

    // Bellman-Ford, but maximizing instead of minimizing.
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;

        for (const Edge& e : edges) {
            // Cannot use an edge from an unreachable vertex.
            if (dist[e.u] == NEG_INF)
                continue;

            if (dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }

        // No more improvements -> no reachable positive cycle
        // can affect any distances.
        if (!changed)
            break;
    }

    // unsafe[v] = true means v is reachable from a reachable
    // positive cycle.
    vector<bool> unsafe(n + 1, false);
    queue<int> q;

    // If an edge can still be relaxed after n-1 iterations,
    // its destination is affected by a positive cycle.
    for (const Edge& e : edges) {
        if (dist[e.u] == NEG_INF)
            continue;

        if (dist[e.v] < dist[e.u] + e.w) {
            if (!unsafe[e.v]) {
                unsafe[e.v] = true;
                q.push(e.v);
            }
        }
    }

    // Every vertex reachable from an unsafe vertex is also unsafe.
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!unsafe[v]) {
                unsafe[v] = true;
                q.push(v);
            }
        }
    }

    // Output answer for every room.
    for (int i = 1; i <= n; i++) {
        if (dist[i] == NEG_INF) {
            cout << "UNREACHABLE\n";
        } else if (unsafe[i]) {
            cout << "UNSAFE\n";
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}