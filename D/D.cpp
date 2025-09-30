#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using vi = vector<int>;
using vll = vector<long long>;

constexpr int INF = 1e9+7;
constexpr ll LINF = (ll)4e18;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> children(n+1);
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        children[p].push_back(i);
    }

    vector<ll> dpA(n+1, 0), dpB(n+1, 0);

    function<void(int)> dfs = [&](int u) {
        for (int v : children[u]) dfs(v);

        ll base = 0;
        vector<ll> gains;
        gains.reserve(children[u].size());
        for (int v : children[u]) {
            base += dpA[v];
            gains.push_back(dpB[v] - dpA[v]);
        }

        sort(gains.begin(), gains.end(), greater<ll>());

        // prefix sums of gains
        int m = (int)gains.size();
        vector<ll> pref(m+1, 0);
        for (int i = 0; i < m; ++i) pref[i+1] = pref[i] + gains[i];

        ll bestB = -LINF;
        ll bestA = -LINF;
        for (int k = 0; k <= m; ++k) {
            ll val = base + pref[k] + (k / 2);
            bestB = max(bestB, val);
            if ((k % 2) == 0) bestA = max(bestA, val);
        }

        if (bestA < -LINF/2) bestA = 0;
        if (bestB < -LINF/2) bestB = 0;

        dpA[u] = bestA;
        dpB[u] = bestB;
    };

    dfs(1);

    cout << dpA[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;

    if (!(cin >> tc)) return 0;
    while(tc--) {
        solve();
    }

    return 0;
}
