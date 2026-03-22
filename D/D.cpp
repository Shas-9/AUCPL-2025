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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> odd;
    vector<ll> even;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i % 2 == 0) {
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    // int nsize = odd.size() < even.size() ? odd.size() : even.size();
    // cout << odd.size() << " " << even.size() << " " << "\n";
    bool flag = true;
    int i = 0;
    for (i; i < odd.size(); i++) {
        if (even[i] >= odd[i]) {
            flag = false;
            break;
        }
    }
    if (even.size() > odd.size()) {
        //cout << even[i] << " " << odd[i - 1] << "\n";
        if (even[i] < odd[i - 1]) {
            flag = false;
        }
    }

    if (flag) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}