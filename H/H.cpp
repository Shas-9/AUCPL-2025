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

ll MOD = 10e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<ll>> knol;
    knol.reserve(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        knol.push_back({(ll)a/b, a, b});
    }


    sort(knol.begin(), knol.end(), [](const vector<ll>& a, const vector<ll>& b) {
        return a[0] <= b[0];
    });

    ll t = 0;

    for (auto vec : knol) {
        ll time = vec[1] + vec[2] * t;
        t += time;
    }

    cout << t % MOD << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}