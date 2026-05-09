#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

void helper(vector<pair<ll, ll>> &term, unordered_map<ll, vector<ll>> &graph, ll room, ll path, ll decisions) {
    auto &children = graph[room];
    if (children.size() == 0) {
        term.push_back({path, decisions});
        return;
    }

    if (children.size() == 1) {
        helper(term, graph, children[0], path + 1, decisions);
        return;
    }

    if (children.size() == 2) {
        helper(term, graph, children[0], path + 1, decisions + 1);
        helper(term, graph, children[1], path + 1, decisions + 1);
        return;
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> graph;

    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<pair<ll, ll>> term;
    helper(term, graph, 1, 0, 0);

    ll num = 0;
    ll denom = 1;
    ll max_denom = 0;
    for (auto [room, prob] : term) {
        max_denom = max(max_denom, prob);
    }

    for (auto [room, prob] : term) {
        num += room * pow(2, max_denom - prob);
    }

    ll temp = pow(2, max_denom);
    ll thingo;
    for (int i = 0; i <= 56; ++i) {
        if ((num & ll(pow(2, i) - 1)) != 0) {
            break;
        }
        thingo = i;
    }
    num /= pow(2, thingo);
    denom = temp / pow(2, thingo);
    cout << num << '/' << denom << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve();
    }

    return 0;
}