#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> c1(n), c2(n);

    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            c1[i] = s[i] == '+';
            c2[i] = !c1[i];
        } else {
            c1[i] = s[i] != '+';
            c2[i] = !c1[i];
        }
    }

    auto count = [&](vector<bool> &cand) {
        int count = cand[0] == 1;
        for (int i = 1; i < n; ++i) {
            count += cand[i - 1] == 0 && cand[i] == 1;
        }
        return count;
    };
    cout << min(count(c1), count(c2)) << '\n';
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