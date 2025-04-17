#include <bits/stdc++.h>

using namespace std;

// void solve() {
    
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> q(n);
    int c;

    for (auto& v : q) {
        cin >> v;
    }
    sort(q.begin(), q.end());

    cout << q[3] << "\n";

    // int tc = 1;
    // // cin >> tc; //comment out if 1 case
    // while(tc--) {
    //     solve();
    // }

    return 0;
}