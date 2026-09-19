#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> getDivisors(ll n) {
	vector<ll> divisors;
	for (ll i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
		}
	}

	return divisors;
}
bool isPrime(ll n, vector<ll>& divs) {
	// vector<ll>divs = getDivisors(n);
	return divs.size() == 0;
}
bool checkIfPrimeOrPrimePower(ll n) {
    vector<ll> divs = getDivisors(n);
    if (isPrime(n, divs)) {
        return true;
    }

    // check if prime to a power
    if (divs.size() == 1) {
        vector<ll> test_divs = getDivisors(divs[0]);

        if (isPrime(divs[0], test_divs)) {
            return true;
        }
    }

    return false;
}
void solve() {
    ll n;
    cin >> n;
     for (auto& div : getDivisors(n)) {
         cout << div << "\n";
     }

    // cout << (isPrime(n) ? "PRIME" : "NOT PRIME") << "\n";
    // // cout << n << "\n";

    // auto divs = getDivisors(4);
    // 
    // for (auto& div : divs) {
    //     cout << div << "\n";
    // }
    if (checkIfPrimeOrPrimePower(n)) {
        cout << "Yes\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}
