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

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int n = (s1.size() + s2.size() + s3.size()) / 2;

    int p1 = 0, p2 = 0, p3 = 0;
    string ans;
    ans.reserve(n);

    for (int i = 0; i < n; i++) {
        bool ok1 = (p2 < (int)s2.size() && s2[p2] == '1') &&
                   (p3 < (int)s3.size() && s3[p3] == '1');

        bool ok2 = (p1 < (int)s1.size() && s1[p1] == '2') &&
                   (p3 < (int)s3.size() && s3[p3] == '2');

        bool ok3 = (p1 < (int)s1.size() && s1[p1] == '3') &&
                   (p2 < (int)s2.size() && s2[p2] == '3');

        if (ok1) {
            ans.push_back('1');
            p2++; p3++;
        } else if (ok2) {
            ans.push_back('2');
            p1++; p3++;
        } else if (ok3) {
            ans.push_back('3');
            p1++; p2++;
        }
    }

    cout << ans << "\n";

    return 0;
}