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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int p = 0;
    mt19937 rng(time(0));

    for(int t = 0; t < 125 && p < 70; t++) {
        int l = 1;
        int r = n;

        cout << l << " " << r << endl;
        cout.flush();

        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cin >> p;
    }

    return 0;
}