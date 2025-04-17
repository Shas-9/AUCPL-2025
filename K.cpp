#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vpii vector<pair<int,int>>
#define vi vector<int>
# define endl "\n"

void solve(vi& arr, vpii& operations, int& n, int& m) {
    unordered_map<ll, ll> mp;
    set<ll> trimex;
    
    for (int i = 0; i <= arr.size() + 2; i++) {
        trimex.insert(i);
    }
    for (const auto& num : arr) {
        mp[num]++;
        trimex.erase(num);
    }

 
    for (const auto& op : operations) {
        ll old_num = arr[op.first];
        if (--mp[old_num] <= 0) {
            trimex.insert(old_num);
            mp.erase(old_num);
        }

        arr[op.first] = op.second;
        mp[op.second]++;
        trimex.erase(op.second);

        int count = 0;
        for (const auto& it : trimex) {
            cout << it << " ";
            count++;
            if (count == 3) break;
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& v : arr) {
        cin >> v;
    }

    int m;
    cin >> m;

    vpii operations(m);
    for (auto& v : operations) {
        cin >> v.first;
        cin >> v.second;
    }

    int tc = 1;
    // cin >> tc; //comment out if 1 case
    while(tc--) {
        solve(arr, operations, n, m);
    }

    return 0;
}