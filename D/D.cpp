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

    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    int odd = 0;
    for (auto [c, f] : freq) {
        if (f % 2 != 0) odd++;
    }

    if (s.size() % 2 == 0 && odd) cout << "no" << "\n";
    else if (s.size() % 2 == 0) cout << "yes" << "\n";
    else if (odd == 1) cout << "yes" << "\n";
    else {
        cout << "no" << "\n";
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}