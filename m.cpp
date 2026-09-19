#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> children(n + 1);
    vector<int> parent(n + 1, 0);

    for (int v = 2; v <= n; v++) {
        cin >> parent[v];
        children[parent[v]].push_back(v);
    }


    vector<vector<int>> cnt(n + 1, vector<int>(m + 1, 0));

    for (int v = 1; v <= n; v++) {
        cnt[v][0] = 1;
    }


    vector<int> order;
    order.reserve(n);

    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        order.push_back(v);

        for (int u : children[v]) {
            st.push(u);
        }
    }

    reverse(order.begin(), order.end());

    for (int v : order) {
        for (int u : children[v]) {
            for (int d = 1; d <= m; d++) {
                cnt[v][d] += cnt[u][d - 1];
            }
        }
    }

    
    vector<int> path;

    int cur = k;
    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    // dp[i] = minimum cost to reach path[i]
    int L = (int)path.size();

    const long long INF = (1LL << 60);
    vector<long long> dp(L, INF);

    dp[0] = 0;

    for (int i = 1; i < L; i++) {
        for (int d = 1; d <= m && d <= i; d++) {
            int from = path[i - d];

            dp[i] = min(
                dp[i],
                dp[i - d] + cnt[from][d]
            );
        }
    }

    cout << dp[L - 1] << '\n';

    return 0;
}