#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, k, bj, bm;
    cin >> n >> k >> bj >> bm;
    vector<int> logos(n);
    vector<int> jay(n);
    for (auto &l : logos) cin >> l;
    for (auto &j : jay) cin >> j;

    vector<int> may_prefix(n + 1), jay_prefix(n + 1);

    for (int i = 0; i < n; ++i) {
        jay_prefix[i + 1] = jay_prefix[i] + (jay[i] ? logos[i] : 0);
        may_prefix[i + 1] = may_prefix[i] + logos[i];
    }
    vector<vector<ll>> dp(k, vector<ll>(n, -1));

    auto jay_score = [&](int l, int r) {
        return jay_prefix[r + 1] - jay_prefix[l];
    };

    auto may_score = [&](int l, int r) {
        return may_prefix[r + 1] - may_prefix[l];
    };

    dp[0][bj - 1] = jay_score(0, bj - 1);
    dp[0][bm - 1] = may_score(0, bm - 1);

    for (int a = 1; a < k; ++a) {
        for (int logo = 0; logo < (a + 1) * bj; ++logo) {
            ll jay{}, may{};

            if (logo >= bj && dp[a - 1][logo - bj] != -1) jay = dp[a - 1][logo - bj] + jay_score(logo - bj + 1, logo);
            if (logo >= bm && dp[a - 1][logo - bm] != -1) may = dp[a - 1][logo - bm] + may_score(logo - bm + 1, logo);
            dp[a][logo] = max(jay, may);
        }
    }

    // for (const auto& row : dp) {
    //     for (const auto & score : row) cout << score << ' ';
    //     cout << '\n';
    // }

    ll max_score = 0;
    for (int i = 0; i < k * bj; ++i) max_score = max(max_score, dp[k - 1][i]);
    cout << max_score << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}