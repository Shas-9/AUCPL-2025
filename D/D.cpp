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

int MAXC = 100001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<int> best_vp(MAXC, 0);
    
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        if (best_vp[c] == 0) {
            best_vp[c] = i;
        }
    }
    
    while (q--) {
        int d;
        cin >> d;
        
        int best_tier = 0, best_id = 0;
        for (int c = 1; (ll)c * c <= d; c++) {
            if (d % c == 0) {
                if (best_vp[c]) {
                    if (c > best_tier) {
                        best_tier = c;
                        best_id = best_vp[c];
                    }
                }
                int other = d / c;
                if (other != c && best_vp[other]) {
                    if (other > best_tier) {
                        best_tier = other;
                        best_id = best_vp[other];
                    }
                }
            }
        }
        
        cout << best_id << "\n";
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}