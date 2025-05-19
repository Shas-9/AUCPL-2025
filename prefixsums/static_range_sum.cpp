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

void solve(vll& psum, int& a, int& b) {
    cout << psum[b] - psum[a] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int q; cin >> q;

    vll arr(n);
    for(ll& x : arr) {
        cin >> x;
    }

    vll psum(n + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        psum[i + 1] = psum[i] + arr[i];
        //cout << psum[i + 1] << endl;
    }
    
    int tc = q;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        int a; cin >> a;
        int b; cin >> b;
        solve(psum, a, b);
    }

    return 0;
}