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

    for (int ops = 0; ops < 125; ops++) {

        int l = 1, r = n;
        cout << l << " " << r << endl;
        cout.flush();

        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> p;

        if (p >= 70) return 0;

        int best_l = -1, best_r = -1;
        int i = 0;

        while (i < n) {
            if (v[i] == 0) {
                int j = i;
                while (j < n && v[j] == 0) j++;
                if (best_l == -1 || j - i > best_r - best_l) {
                    best_l = i;
                    best_r = j - 1;
                }
                i = j;
            } else {
                i++;
            }
        }

        if (best_l == -1) return 0;

        cout << best_l + 1 << " " << best_r + 1 << endl;
        cout.flush();

        for (int k = 0; k < n; k++) cin >> v[k];
        cin >> p;

        if (p >= 70) return 0;

        ops++;
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}