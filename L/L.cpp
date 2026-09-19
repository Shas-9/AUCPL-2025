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

vector<int> kmpSearch(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> occ;
    if (m > n) return occ;

    vector<int> fail(m, 0);
    for (int i = 1; i < m; i++) {
        int j = fail[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
        if (pattern[i] == pattern[j]) j++;
        fail[i] = j;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) j = fail[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            occ.push_back(i - m + 1);
            j = fail[j - 1];
        }
    }
    return occ;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    string files, name;
    cin >> files >> name;

    vector<int> pos = kmpSearch(files, name);
    int total = (int)pos.size();

    if (total < k) {
        cout << "impossible\n";
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < total; i++) {
        int len = pos[i + k - 1] - pos[i] - m + 2;
        ans = min(ans, max(1, len));
    }

    cout << ans << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}