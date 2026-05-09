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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> big;
    vector<ll> small;

    for (int i = 0; i < 3; i++) {
        ll x;
        cin >> x;
        big.push_back(x);
    }

    for (int i = 0; i < 3; i++) {
        ll x;
        cin >> x;
        small.push_back(x);
    }

    sort(big.begin(), big.end());
    sort(small.begin(), small.end());

    for (int i = 0; i < 3; i++) {
        if (small[i] > big[i]) {
            cout << "No" << "\n";
            return 0;
        }
    }

    cout << "Yes" << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}