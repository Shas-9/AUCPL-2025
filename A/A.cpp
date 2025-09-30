#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())

using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
using vi = vector<int>;
using vll = vector<long long>;

constexpr int INF = 1e9+7;
constexpr ll LINF = 1e18;

struct PrefixSum2D {
    int n, m;
    vector<vector<int>> psum;

    PrefixSum2D(int n, int m) : n(n), m(m), psum(n+1, vector<int>(m+1, 0)) {}

    void build(const vector<vector<int>>& a) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                psum[i][j] = a[i][j] + psum[i-1][j] +
                            psum[i][j-1] - psum[i-1][j-1];
            }
        }
    }

    int query(int r1, int c1, int r2, int c2) {
        if (r1 > r2 || c1 > c2) return 0;
        return psum[r2][c2] - psum[r1-1][c2]  - psum[r2][c1-1] +
                psum[r1-1][c1-1];
    }
};

int n, q;
vector<string> grid;

void solve() {
    cin >> n >> q;
    grid.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        grid[i] = " " + s;
    }

    vector<vector<int>> good(n + 1, vector<int>(n + 1, 0));
    for (int r = 1; r < n; r++) {
        for (int c = 1; c < n; c++) {
            if (grid[r][c] == '.' && grid[r][c+1] == '.' &&
                grid[r+1][c] == '.' && grid[r+1][c+1] == '.') {
                    good[r][c] = 1;
                }
        }
    }

    PrefixSum2D ps(n, n);
    ps.build(good);

    while (q--) {
        int u, d, l, r;
        cin >> u >> d >> l >> r;

        int res = ps.query(u, l, d-1, r-1);
        cout << res << '\n';
    }
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