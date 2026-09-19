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

struct Edge {
    int u, v;
    ll w;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

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

    // maximise
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;

        for (const Edge& e : edges) {
            if (dist[e.u] == NEG_INF)
                continue;

            if (dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }


        if (!changed)
            break;
    }

    // unsafe[v] = true means v is part of apositive cycle
    vector<bool> unsafe(n + 1, false);
    queue<int> q;


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

    // vertexes from unsafe are also unsafe
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