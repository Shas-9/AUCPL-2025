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

    vector<string> front(n), side(n), top(n);
    for (int i = 0; i < n; i++) cin >> front[i];
    for (int i = 0; i < n; i++) cin >> side[i];
    for (int i = 0; i < n; i++) cin >> top[i];

    long long count = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (front[y][x] != '#') continue;
            for (int z = 0; z < n; z++) {
                if (side[y][z] == '#' && top[x][z] == '#') {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";
    return 0;

    return 0;
}