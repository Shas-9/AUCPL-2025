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

    vector<int> v(n);
    int p = 0;
    int ops = 0;

    while (ops < 125) {
        cin >> v[0];
        for (int i = 1; i < n; i++) cin >> v[i];
        cin >> p;

        if (p >= 70) break;

        int l = -1;

        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                l = i;
                break;
            }
        }

        if (l == -1) break;

        int r = l;
        while (r + 1 < n && v[r + 1] == 0) r++;

        cout << l + 1 << " " << r + 1 << "\n";
        cout.flush();

        ops++;
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}