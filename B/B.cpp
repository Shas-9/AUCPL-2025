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

int parent[1000005];
ll sz[1000005];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int row, col, q;
    cin >> row >> col >> q;
    
    for (int i = 0; i < row * col; i++) {
        parent[i] = i;
        sz[i] = 100;
    }
    
    auto idx = [&](int r, int c) { return (r-1)*col + (c-1); };
    
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        unite(idx(r1,c1), idx(r2,c2));
        cout << sz[find(idx(r1,c1))] << "\n";
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}