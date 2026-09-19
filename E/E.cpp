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

    int n;
    cin >> n;
    string s;
    cin >> s;

    ll ops = 0;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'T') {
            s[i] = 'H';
            s[i + 1] = (s[i + 1] == 'H') ? 'T' : 'H';
            ops++;
        }
    }

    if (s[n - 1] == 'T') {
        cout << -1 << "\n";
    } else {
        cout << ops << "\n";
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}