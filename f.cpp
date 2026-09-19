#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt[10];
int hourDigits;
int totalDigits;

string answer;

bool backtrack(int pos, string &cur) {
    
    if (pos == totalDigits) {
        answer = cur;
        return true;
    }

    for (int d = 0; d <= 9; d++) {
        if (cnt[d] == 0)
            continue;

        // no leading 0
        if (pos == 0 && d == 0)
            continue;

        // 0-5
        if (pos == hourDigits && d > 5)
            continue;

        // 0-5
        if (pos == hourDigits + 2 && d > 5)
            continue;

        
        cnt[d]--;
        cur.push_back(char('0' + d));

        
        if (backtrack(pos + 1, cur))
            return true;

        
        cur.pop_back();
        cnt[d]++;
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string hours, minutes, seconds;
    cin >> hours >> minutes >> seconds;

    hourDigits = hours.size();

    string digits = hours + minutes + seconds;
    totalDigits = digits.size();

    for (char c : digits)
        cnt[c - '0']++;

    string cur;
    backtrack(0, cur);


    cout << answer.substr(0, hourDigits) << ' '
         << answer.substr(hourDigits, 2) << ' '
         << answer.substr(hourDigits + 2, 2) << '\n';

    return 0;
}