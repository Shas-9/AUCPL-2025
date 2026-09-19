#include <bits/stdc++.h>
using namespace std;

int cnt[10];
int hourDigits;
int totalDigits;

string answer;

bool backtrack(int pos, string &cur) {
    
    if (pos == totalDigits) {
        answer = cur;
        return true;
    }

    // Try digits from smallest to largest.
    for (int d = 0; d <= 9; d++) {
        if (cnt[d] == 0)
            continue;

        // Hours cannot have a leading zero.
        if (pos == 0 && d == 0)
            continue;

        // Tens digit of minutes must be 0-5.
        if (pos == hourDigits && d > 5)
            continue;

        // Tens digit of seconds must be 0-5.
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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