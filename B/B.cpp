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
    
    vector<int> decided(n, -1);
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') decided[i] = 1;
        else if (s[i] != '?') decided[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (!isdigit(s[i])) continue;
        int d = s[i] - '0';
        
        int definite = 0;
        vector<int> undecided_pos;
        
        for (int j : {i - 1, i + 1}) {
            if (j < 0 || j >= n) continue;
            if (decided[j] == 1) definite++;
            else if (decided[j] == -1) undecided_pos.push_back(j);
        }
        
        int needed = d - definite;
        int undecided = (int)undecided_pos.size();
        
        if (needed == undecided) {
            for (int p : undecided_pos) decided[p] = 1;
        } else if (needed == 0) {
            for (int p : undecided_pos) decided[p] = 0;
        } else {
            decided[undecided_pos[0]] = 0;
            decided[undecided_pos[1]] = 1;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (decided[i] == -1) decided[i] = 0;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) count += decided[i];
    cout << count << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}