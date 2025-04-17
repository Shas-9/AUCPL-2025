#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {

    ll n1;
    cin >> n1;

    vector<pair<ll,ll>> tom(n1);
    for (auto& v : tom) {
        cin >> v.first;
        cin >> v.second;
    }

    ll n2;
    cin >> n2;

    vector<pair<ll,ll>> pat(n2);
    for (auto& v : pat) {
        cin >> v.first;
        cin >> v.second;
    }

    ll tomx = 0, tomy = 0, patx = 0, paty = 0;

    ll min_dist = LLONG_MAX;

    for (ll i = 0; i < (ll)tom.size(); i++) {

        for (ll j = 0; j < (ll)pat.size(); j++) {

            ll dx = (tom[i].first - pat[j].first);
            ll dy = (tom[i].second - pat[j].second);
            ll dist = dx*dx + dy*dy;

            if (dist == 0) continue;

            if (dist < min_dist) {

                min_dist = dist;

                tomx = tom[i].first;
                tomy = tom[i].second;

                patx = pat[j].first;
                paty = pat[j].second;

            }
        }

        

    }

    cout << tomx << " " << tomy << '\n';
    cout << patx << " " << paty << '\n';

    // for (auto& tom_val : tom) {
    //     for (auto& pat_val : pat) {
    //         ll dx = (tom_val.first - pat_val.first);
    //         ll dy = (tom_val.second - pat_val.second);
    //         ll dist = dx*dx + dy*dy;
            
    //         if (dist < min_dist && dist != 0) {
    //             tom_best = tom_val;
    //             pat_best = pat_val;
    //             min_dist = dist;
    //         }
    //     }

    // }

    // cout << tom_best.first << " " << tom_best.second << '\n';
    // cout << pat_best.first << " " << pat_best.second << '\n';


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tc = 1;
    while(tc--) {
        solve();
    }

    return 0;
}