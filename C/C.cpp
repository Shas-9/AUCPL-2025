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

#include <bits/stdc++.h>
using namespace std;

char query(int r, int c) {
    cout << "? " << r << " " << c << "\n";
    cout.flush();
    char ch;
    cin >> ch;
    return ch;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    // APPROACH: Diagonal binary search with multi-query verification.
    //
    // Maintain a bounding box [r_lo, r_hi] x [c_lo, c_hi] for the target desk.
    // Each step: query the midpoint of the bounding box MULTIPLE TIMES.
    //
    //   Non-target coworkers answer DETERMINISTICALLY (same answer every time).
    //   Target coworker answers UNIFORMLY AT RANDOM (each of U/D/L/R with prob 1/4).
    //
    // Detection strategy: query 5 times.
    //   - If all 5 agree: non-target cell (P(target fakes 5 same) = 4*(1/4)^5 ≈ 0.4%)
    //   - If NOT all 5 agree: this is the target cell. Answer immediately.
    //   - Also: if the agreed direction is impossible given the bounding box, 
    //     it's the target faking (e.g., says U but mid_r is already at r_lo).
    //
    // Each "step" uses 5 queries. Steps = log2(N) + log2(M) ≤ log2(500)*2 ≈ 18.
    // Total queries ≤ 5 * 18 = 90. Well within 150.
    //
    // P(ever wrongly trusting target over entire run) ≤ 18 * 0.4% ≈ 7%.
    // We can push to 6 queries per step for ~99.98% reliability with ≤ 108 queries.

    int r_lo = 1, r_hi = N, c_lo = 1, c_hi = M;
    
    while (r_lo < r_hi || c_lo < c_hi) {
        int mid_r = (r_lo + r_hi) / 2;
        int mid_c = (c_lo + c_hi) / 2;
        
        // Query 6 times (6 queries/step * 18 steps = 108 max, within 150)
        const int REPS = 6;
        char answers[REPS];
        for (int i = 0; i < REPS; i++) {
            answers[i] = query(mid_r, mid_c);
        }
        
        // Check if all agree
        bool all_same = true;
        for (int i = 1; i < REPS; i++) {
            if (answers[i] != answers[0]) { all_same = false; break; }
        }
        
        if (!all_same) {
            // Mixed answers -> this IS the target cell
            cout << "! " << mid_r << " " << mid_c << "\n";
            cout.flush();
            return 0;
        }
        
        char resp = answers[0];
        
        // Sanity check: does this direction make sense given our bounding box?
        // If the direction would push the target out of the valid search space, 
        // it must be a random coincidence from the target cell.
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
        
        // Trust the direction and narrow the bounding box
        if      (resp == 'U') r_hi = mid_r - 1;
        else if (resp == 'D') r_lo = mid_r + 1;
        else if (resp == 'L') c_hi = mid_c - 1;
        else                  c_lo = mid_c + 1; // R
    }
    
    // Narrowed to a single cell: this must be the target
    cout << "! " << r_lo << " " << c_lo << "\n";
    cout.flush();
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}