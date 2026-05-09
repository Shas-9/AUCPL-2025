#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int N;
    cin >> N;
    vector<int> years(N);
    for (int i = 0; i < N; ++i) {
        cin >> years[i];
    }

    vector<bool> sieve(3101);
    for (int i = 2; i <= 3100; ++i) {
        if (sieve[i]) continue;
        for (int j = 2; i * j <= 3100; ++j) {
            sieve[i * j] = true;
        }
    }

    for (int year : years) {
        if (sieve[year]) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
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