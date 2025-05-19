#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define um unordered_map
#define us unordered_set

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vll arr(n);
    for (auto& val : arr) {
        cin >> val;
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        cout << upper_bound(arr.begin(), arr.end(), end) - 
                lower_bound(arr.begin(), arr.end(), start) << endl;
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}