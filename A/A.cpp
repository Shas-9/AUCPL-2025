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

int main() {
    int n, l, h;
    cin >> n >> l >> h;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto validShifts = [&](int note) {
        set<int> s;
        for (int oct = -10; oct <= 10; oct++) {
            int shifted = note + oct * 12;
            if (shifted >= l && shifted <= h) s.insert(oct);
        }
        return s;
    };

    vector<int> dp(n + 1, 0);
    dp[0] = INT_MAX;

    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        set<int> common;
        for (int j = i - 1; j >= 0; j--) {
            set<int> vs = validShifts(a[j]);
            if (j == i - 1) {
                common = vs;
            } else {
                set<int> inter;
                set_intersection(common.begin(), common.end(),
                                 vs.begin(), vs.end(),
                                 inserter(inter, inter.begin()));
                common = inter;
            }
            if (common.empty()) break;
            if (dp[j] > 0 || j == 0) {
                int segLen = i - j;
                int candidate = min(dp[j], segLen);
                dp[i] = max(dp[i], candidate);
            }
        }
    }

    cout << dp[n] << endl;
}