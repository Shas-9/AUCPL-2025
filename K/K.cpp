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

// BIT (Fenwick Tree) where each node holds a sorted list of salaries.
// Supports:
//   update(pos, val): insert val at position pos
//   query(pos, val):  count of values > val in positions [1..pos]

struct MergeSortBIT {
    int n;
    vector<vector<int>> tree;

    MergeSortBIT(int n) : n(n), tree(n + 1) {}

    // Call this once before queries to sort all lists (offline build not used here;
    // we insert dynamically and keep sorted via insertion)
    void update(int pos, int val) {
        for (; pos <= n; pos += pos & -pos) {
            // Insert val into sorted position
            auto& v = tree[pos];
            v.insert(lower_bound(v.begin(), v.end(), val), val);
        }
    }

    // Count of values strictly greater than val in positions [1..pos]
    long long query(int pos, int val) {
        long long cnt = 0;
        for (; pos > 0; pos -= pos & -pos) {
            auto& v = tree[pos];
            // Count elements > val
            cnt += (long long)(v.end() - upper_bound(v.begin(), v.end(), val));
        }
        return cnt;
    }

    // Count of values strictly greater than val in positions [l..r]
    long long query(int l, int r, int val) {
        if (l > r) return 0;
        return query(r, val) - query(l - 1, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> pay(n + 1);
    for (int i = 1; i <= n; i++) cin >> pay[i];

    // seat[s] = employee number assigned to seat s
    // We need: for employee i, what seat are they in?
    // Input: n integers; position in line = seat number, value = employee number
    vector<int> emp_to_seat(n + 1); // emp_to_seat[employee] = seat
    for (int seat = 1; seat <= n; seat++) {
        int emp;
        cin >> emp;
        emp_to_seat[emp] = seat;
    }

    MergeSortBIT bit(n);

    long long total = 0;

    // Hire employees in order 1 to n
    for (int emp = 1; emp <= n; emp++) {
        int seat = emp_to_seat[emp];
        int p = pay[emp];

        // Count already-hired with higher salary to the LEFT (seats 1..seat-1)
        long long left_higher = bit.query(1, seat - 1, p);

        // Count already-hired with higher salary to the RIGHT (seats seat+1..n)
        long long right_higher = bit.query(seat + 1, n, p);

        total += left_higher * right_higher;

        // Insert this employee
        bit.update(seat, p);
    }

    cout << total << "\n";

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