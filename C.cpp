#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve(vector<vector<int>>& lines, unordered_set<int>& unique, vector<int>& visited, int currLength, int currPoint) {
    if (visited[currPoint] != 0) {
        int dist = currLength - visited[currPoint];

        if (dist >= 3) {
            unique.insert(dist);
        }
        return;
    }

    visited[currPoint] = currLength;
    
    for (auto point : lines[currPoint]) {
        solve(lines, unique, visited, currLength + 1, point);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> lines(n+1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        lines[a].push_back(b);
        lines[b].push_back(a);
    }

    unordered_set<int> unique;
    
    for (int i = 1; i <= n; i++) {
        vector<int> visited(n+1);
        solve(lines, unique, visited, 0, i);
    }

    cout << unique.size() << "\n";

    // int tc = 1;
    // // cin >> tc; //comment out if 1 case
    // while(tc--) {
    //     solve();
    // }

    return 0;
}