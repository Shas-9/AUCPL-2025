#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i);
#define all(x) begin(x), end(x);
#define sz(x) (int)(x).size();
#define pb push_back;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int INF = 1e9+7;
constexpr ll LINF = 1e18;

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll h = 0;
    ll w = 0;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '#') h++;
    }

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '#') w++;
    }

    cout << h * w << '\n';

    return 0;
}