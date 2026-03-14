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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int i1=0, i2=0, i3=0;
    string res;

    while(i1 < s1.size() || i2 < s2.size() || i3 < s3.size()) {
        set<char> possible = {'1','2','3'};

        if(i1 < s1.size()) possible.erase(s1[i1]);
        if(i2 < s2.size()) possible.erase(s2[i2]);
        if(i3 < s3.size()) possible.erase(s3[i3]);

        char winner = *possible.begin();
        res.push_back(winner);

        if(winner != '1' && i1 < s1.size() && s1[i1] == winner) i1++;
        if(winner != '2' && i2 < s2.size() && s2[i2] == winner) i2++;
        if(winner != '3' && i3 < s3.size() && s3[i3] == winner) i3++;
    }

    cout << res << "\n";

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}