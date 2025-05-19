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

    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<array<int, 3>> queries(m);
    for (auto& query : queries) {
        cin >> query[0] >> query[1] >> query[2];
    }

    vll diff(m + 2);
    vll add(n + 2, 0);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        diff[x]++;
        diff[y + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        // apply prefix sum on diff array
        diff[i] += diff[i - 1];

        // compute 2nd diff array
        add[queries[i - 1][0]] += diff[i] * queries[i - 1][2];
        add[queries[i - 1][1] + 1] -= diff[i] * queries[i - 1][2];
    }

    for (int i = 1; i <= n; i++) {
        add[i] += add[i - 1];
        cout << arr[i] + add[i] << ' ';
    }
    cout << endl;

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}