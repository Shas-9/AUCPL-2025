#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

void solve(vector<vector<ll>>& pipes, vector<pair<ll, ll>> queries, int n, int m, int q) {
    vector<vector<ll>> flow(n + 1, vector<ll>(n + 1, LLONG_MIN));

    for (int i = 1; i <= n; i++) {
        flow[i][i] = LLONG_MAX;
    }

    for (const auto& vec : pipes) {
        flow[vec[0]][vec[1]] = max(flow[vec[0]][vec[1]], vec[2]);
        flow[vec[1]][vec[0]] = max(flow[vec[1]][vec[0]], vec[2]);        
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (flow[i][k] != LLONG_MIN && flow[k][j] != LLONG_MIN) {
                    flow[i][j] = max(flow[i][j], min(flow[i][k], flow[k][j]));
                }
            }
        }
    }

    for (const auto& [a, b] : queries) {
        if (flow[a][b] == LLONG_MIN) cout << -1 << endl;
        else {
            cout << flow[a][b] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<ll>> pipes(m);
    for (auto& v : pipes) {
        int a, b, w;
        cin >> a >> b >> w;
        v = {a, b, w};
    }
    int q;
    cin >> q;
    vector<pair<ll, ll>> queries(q);
    for (auto& query : queries) {
        int a, b;
        cin >> a >> b;
        query = make_pair(a, b);
    }

    // for (const auto& v : pipes) {
    //     cout << v[0] << " " << v[1] << " " << v[2] << endl;
    // }
    // for (const auto& query : queries) {
    //     cout << query.first << " " << query.second << endl;
    // }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve(pipes, queries, n, m, q);
    }

    return 0;
}