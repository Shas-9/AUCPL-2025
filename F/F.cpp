#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define inf INT_MAX;

// struct room {
//     int sand = inf;
//     bool wall = false;
//     bool exit = false;
//     bool visited = false;
// };

// vector<int> fast_dir = {0, 1, 0, -1, 0};

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     queue<array<int, 3>> sand;
//     array<int, 3> marcus;
//     vector<vector<room>> tomb(n, vector<room>(m));
//     for (int row = 0; row < n; ++row) {
//         for (int col = 0; col < m; ++col) {
//             char val;
//             cin >> val;
//             switch (val) {
//                 case '#':
//                     tomb[row][col].wall = true;
//                     break;
//                 case 'M':
//                     marcus = {row, col, 0};
//                     break;
//                 case 'E':
//                     tomb[row][col].exit = true;
//                     break;
//                 case '*':
//                     tomb[row][col].sand = 0;
//                     sand.push({row, col, 0});
//                     break;
//             }
//         }
//     }

//     // bfs through sand
//     int min_time = inf;
//     while (!sand.empty()) {
//         auto [row, col, time] = sand.front(); sand.pop();
    
//         tomb[row][col].sand = time;
//         if (tomb[row][col].exit) min_time = min(min_time, time);
//         for (int i = 0; i < 4; ++i) {
//             int new_row = row + fast_dir[i];
//             int new_col = col + fast_dir[i + 1];
//             if (new_row < 0 || new_row >= n) continue;
//             if (new_col < 0 || new_col >= m) continue;
//             auto &next_room = tomb[new_row][new_col];
//             if (next_room.sand <= time + 1 || next_room.wall) {
//                 continue;
//             }
//             sand.push({new_row, new_col, time + 1});
//         }
//     }

//     // marcus bfs passage
//     queue<array<int, 3>> pos;
//     if (tomb[marcus[0]][marcus[1]].sand == 1) {
//         cout << -1 << '\n';
//         return;
//     }
//     pos.push(marcus);
//     while (!pos.empty()) {
//         auto [row, col, time] = pos.front(); pos.pop();
//         tomb[row][col].visited = true;
//         for (int i = 0; i < 4; ++i) {
//             int new_row = row + fast_dir[i];
//             int new_col = col + fast_dir[i + 1];
//             if (new_row < 0 || new_row >= n) continue;
//             if (new_col < 0 || new_col >= m) continue;
//             auto &next_room = tomb[new_row][new_col];
//             if (next_room.visited || next_room.sand <= time + 1 || next_room.wall || time + 1 >= min_time) {
//                 continue;
//             }
//             if (next_room.exit) {
//                 cout << time + 1 << endl;
//                 return;
//             }
//             pos.push({new_row, new_col, time + 1});
//         }
//     }
//     cout << -1 << '\n';
// }



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> sand(n, vector<int>(m, INT_MAX));
    queue<pii> q;

    pii start, exitPos;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                sand[i][j] = 0;
                q.push({i, j});
            }
            if (grid[i][j] == 'M') start = {i, j};
            if (grid[i][j] == 'E') exitPos = {i, j};
        }
    }

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    if (abs(start.first - exitPos.first) < 2 && abs(start.second - exitPos.second) < 2) {
        cout << -1 << "\n";
        return 0;
    }

    
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#') continue;

            if (sand[nr][nc] > sand[r][c] + 1) {
                sand[nr][nc] = sand[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pii> mq;

    if (sand[start.first][start.second] == 0) {
        cout << -1 << "\n";
        return 0;
    }

    dist[start.first][start.second] = 0;
    mq.push(start);

    while (!mq.empty()) {
        auto [r, c] = mq.front(); mq.pop();
        int t = dist[r][c];

        // reached exit
        if (make_pair(r, c) == exitPos) {
            cout << t << "\n";
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            int nt = t + 1;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#') continue;
            if (dist[nr][nc] != -1) continue;

            
            if (sand[nr][nc] <= nt) continue;

            dist[nr][nc] = nt;
            mq.push({nr, nc});
        }
    }

    cout << -1 << "\n";
    return 0;


    // int tc = 1;
    // // cin >> tc; //comment out if 1 case
    // while(tc--) {
    //     solve();
    // }

    // return 0;
}
