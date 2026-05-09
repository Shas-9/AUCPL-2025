#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int N;
    cin >> N;
    vector<int> weights(N);
    for (auto &w: weights) cin >> w;
    int val = 0;
    for (int i = 0; i < N - 1; ++i) {
        int diff = abs(weights[i] - weights[i + 1]);
        val = gcd(val, diff);
    }
    cout << val << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}