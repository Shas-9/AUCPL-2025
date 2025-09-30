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
constexpr ll LINF = 1e18;

    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int s; cin >> s;

    if (s % gcd(n, m) != 0) {cout << "0.0000" << '\n'; return 0;}

    vector<double> dp(s + max(n, m) + 1, 0.0);
    dp[s] = 1.0;

    for (int cur = s - 1; cur >= 0; --cur) {
        double prob = 0.0;
        prob += 0.5 * dp[cur + n];
        prob += 0.5 * dp[cur + m];
        dp[cur] = prob;
    }

    cout << fixed << setprecision(4) << dp[0] << '\n';

    return 0;
}