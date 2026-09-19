#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> as(n);
    for (auto &a : as) cin >> a;

    vector<int> set_bits(32, 0);

    for (const auto &a : as) {
        bitset<32> bits(a);
        for (int i = 0; i < 32; ++i) {
            set_bits[i] += bits.test(i) == true;
        }
    }

    ll max = 0;
    int a_i = as[0];
    for (const auto &a : as) {
        bitset<32> bits(a);
        ll cand = 0;
        for (int i = 0; i < 32; ++i) {
            ll num = bits.test(i) ? n - set_bits[i] : set_bits[i];
            cand += num * (1 << i);
        }
        if (cand > max || cand == max && a < a_i) {
            max = cand;
            a_i = a;
        }
    }

    cout << a_i << '\n';
}