#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // Total subarrays
    ll total = 1LL * n * (n + 1) / 2;

    ll noR = 0;
    {
        ll len = 0;
        for (char c : s) {
            if (c == 'R') {
                noR += len * (len + 1) / 2;
                len = 0;
            } else {
                len++;
            }
        }
        noR += len * (len + 1) / 2;
    }
    ll total_with_R = total - noR;

    ll bad = 0;
    {
        int i = 0;
        while (i < n) {
            if (s[i] == 'S') { i++; continue; }
            int j = i;
            while (j < n && s[j] != 'S') j++;
            int L = j - i;
            ll block_total = 1LL * L * (L + 1) / 2;

            ll onlyR = 0, onlyP = 0;
            ll len = 0; char type = 0;
            for (int k = i; k < j; k++) {
                if (s[k] == type) {
                    len++;
                } else {
                    if (type == 'R') onlyR += 1LL * len * (len + 1) / 2;
                    if (type == 'P') onlyP += 1LL * len * (len + 1) / 2;
                    type = s[k];
                    len = 1;
                }
            }
            if (type == 'R') onlyR += 1LL * len * (len + 1) / 2;
            if (type == 'P') onlyP += 1LL * len * (len + 1) / 2;

            bad += block_total - onlyR - onlyP;
            i = j;
        }
    }

    cout << (total_with_R - bad) << "\n";
    return 0;
}