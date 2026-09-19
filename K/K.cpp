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

struct Tree {
    int n;
    vector<vector<int>> tree;

    Tree(int n) : n(n), tree(n + 1) {}

    void update(int pos, int val) {
        for (pos; pos <= n; pos += pos & -pos) {
            auto& v = tree[pos];
            v.insert(lower_bound(v.begin(), v.end(), val), val);
        }
    }

    ll query(int pos, int val) {
        ll count = 0;
        for (pos; pos > 0; pos -= pos & -pos) {
            auto& v = tree[pos];
            count += (ll)(v.end() - upper_bound(v.begin(), v.end(), val));
        }
        return count;
    }

    ll query(int l, int r, int val) {
        if (l > r) return 0;
        return query(r, val) - query(l - 1, val);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> pay(n + 1);
    for (int i = 1; i <= n; i++) cin >> pay[i];

    vector<int> emp_to_seat(n + 1);
    for (int seat = 1; seat <= n; seat++) {
        int emp;
        cin >> emp;
        emp_to_seat[emp] = seat;
    }

    Tree bit(n);

    ll total = 0;

    for (int emp = 1; emp <= n; emp++) {
        int seat = emp_to_seat[emp];
        int p = pay[emp];

        ll left_higher = bit.query(1, seat - 1, p);

        ll right_higher = bit.query(seat + 1, n, p);

        total += left_higher * right_higher;

        bit.update(seat, p);
    }

    cout << total << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}