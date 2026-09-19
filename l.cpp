#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef array<ll, 3> arr3;

void solve() {
    int n, S;
    cin >> n >> S;

    vector<ll> a(n);
    for (auto& ai : a) cin >> ai;

    vector<vector<arr3>> dp(n, vector<arr3>(n));
    dp[0][0] = {S, 1, a[0]};
    
    for (int i = 1; i < n; ++i) {
        auto &[cost, length, lomx] = dp[0][i - 1];
        if (a[i] > lomx) {
            dp[0][i] = {cost + ((a[i] - lomx) * length), length + 1, a[i]};
        }
        else {
            dp[0][i] = {cost + (lomx - a[i]), length + 1, lomx};
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ll new_group = dp[i - 1][j - 1][0] + 3;

            auto [cost, length, lomx] = dp[i][j - 1];
            ll same_group;
            if (a[j] > lomx) {
                same_group = cost + ((a[j] - lomx) * length);
            }
            else {
                same_group = cost + (lomx - a[j]);
                lomx = a[j];
            }

            if (new_group < )
        }
    }

    for (const auto& d : dp[0]) cout << d[0] << ' ';
    cout << '\n';
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