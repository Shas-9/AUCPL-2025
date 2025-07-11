#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define um unordered_map
#define us unordered_set

void solve() {
    
}

void dfs(us<int>& visited, vector<vi>& adj, int node) {
    for (int n : adj[node]) {
        if (!visited.count(node)) {
            visited.insert(node);
            cout << "from: " << node << " visiting: " << n << endl;
            dfs(visited, adj, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vi> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    us<int> visited;
    vi components;
    for (int i = 1; i <= n; i++) {
        if (visited.count(i)) continue;

        visited.insert(i);
        components.push_back(i);
        cout << "new: " << i << endl;
        dfs(visited, adj, i);
    }
    cout << endl;
    cout << components.size() - 1 << endl;
    for (int i = 0; i < components.size() - 1; i++) {
        cout << components[i] << ' ' << components[i + 1] << endl;
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}