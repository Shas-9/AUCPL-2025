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

char query(int r, int c) {
    cout << "? " << r << " " << c << "\n";
    cout.flush();
    char ch;
    cin >> ch;
    return ch;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int r_lo = 1, r_hi = n, c_lo = 1, c_hi = m;
    
    while (r_lo < r_hi || c_lo < c_hi) {
        int mid_r = (r_lo + r_hi) / 2;
        int mid_c = (c_lo + c_hi) / 2;
        
        const int reps = 6;
        char answers[reps];
        for (int i = 0; i < reps; i++) {
            answers[i] = query(mid_r, mid_c);
        }
        
        bool all_same = true;
        for (int i = 1; i < reps; i++) {
            if (answers[i] != answers[0]) { all_same = false; break; }
        }
        
        if (!all_same) {
            cout << "! " << mid_r << " " << mid_c << "\n";
            cout.flush();
            return 0;
        }
        
        char resp = answers[0];
        
        bool impossible = false;
        if (resp == 'U' && mid_r <= r_lo) impossible = true;
        if (resp == 'D' && mid_r >= r_hi) impossible = true;
        if (resp == 'L' && mid_c <= c_lo) impossible = true;
        if (resp == 'R' && mid_c >= c_hi) impossible = true;
        
        if (impossible) {
            cout << "! " << mid_r << " " << mid_c << "\n";
            cout.flush();
            return 0;
        }
        
        if (resp == 'U') r_hi = mid_r - 1;
        else if (resp == 'D') r_lo = mid_r + 1;
        else if (resp == 'L') c_hi = mid_c - 1;
        else c_lo = mid_c + 1;
    }
    
    cout << "! " << r_lo << " " << c_lo << "\n";
    cout.flush();

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}