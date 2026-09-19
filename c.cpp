#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n < 3) {
        cout << n << endl;
        return;
    }

    ll opt = m * 3;
    if (opt >= (n + 2)) {
        ll rem = n % 3;
        ll exp = n / 3;
        if (rem == 1) exp -= 1;
        ll ans = pow(3, exp);
        if (rem == 2) ans *= 2;
        if (rem == 1) ans *= 4;
        cout << ans << '\n';
        return;
    }

    ll diff = n - opt;
    ll dist = diff / m;
    ll rem = diff % m;

    ll ans = pow(3 + dist + 1, rem);
    ans *= pow(3 + dist, m - rem);
    cout << ans << '\n';
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