#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i);
#define all(x) begin(x), end(x);
#define sz(x) (int)(x).size();
#define pb push_back;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

constexpr int INF = 1e9+7;
constexpr ll LINF = 1e18;

void solve() {
    
}

int n, m;
vector<int> baseVal;  
vector<int> expVal;    

struct Node {
    int win[2]; 
    int len;    
    Node() { win[0]=win[1]=0; len=0; }
};
vector<Node> seg;

inline int cmp_pow_idx(int a, int b) {
    if (a == b) return 0;
    if (expVal[a] == expVal[b]) {
        if (baseVal[a] < baseVal[b]) return -1;
        if (baseVal[a] > baseVal[b]) return 1;
        return 0;
    }
    if (expVal[a] > expVal[b]) {
        int diff = expVal[a] - expVal[b];
        if (diff >= 60) return 1; 
        __int128 lhs = ( (__int128) baseVal[a] ) << diff;
        __int128 rhs = (__int128) baseVal[b];
        if (lhs < rhs) return -1;
        if (lhs > rhs) return 1;
        return 0;
    } else {
        int diff = expVal[b] - expVal[a];
        if (diff >= 60) return -1; 
        __int128 lhs = (__int128) baseVal[a];
        __int128 rhs = ( (__int128) baseVal[b] ) << diff;
        if (lhs < rhs) return -1;
        if (lhs > rhs) return 1;
        return 0;
    }
}

inline int cmp_choose(int a, int b, int comp) {
    if (a == b) return a;
    int rel = cmp_pow_idx(a, b);
    if (rel == 0) return a;
    if (comp == 0) { // summer: larger
        return (rel > 0 ? a : b);
    } else { // winter: smaller
        return (rel < 0 ? a : b);
    }
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].len = 1;
        seg[idx].win[0] = seg[idx].win[1] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(idx << 1, l, mid);
    build(idx << 1|1, mid+1, r);
    seg[idx].len = seg[idx << 1].len + seg[idx << 1|1].len; 
    int h = __builtin_ctz(seg[idx].len);
    for (int s0 = 0; s0 <= 1; ++s0) {
        int comp = (s0 + (h - 1)) & 1;
        int left_w = seg[idx << 1].win[s0];
        int right_w = seg[idx << 1|1].win[s0];
        seg[idx].win[s0] = cmp_choose(left_w, right_w, comp);
    }
}

void update(int idx, int l, int r, int pos) {
    if (l == r) {
        seg[idx].win[0] = seg[idx].win[1] = l;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(idx << 1, l, mid, pos);
    else update(idx << 1|1, mid+1, r, pos);
    int h = __builtin_ctz(seg[idx].len);
    for (int s0 = 0; s0 <= 1; ++s0) {
        int comp = (s0 + (h - 1)) & 1;
        int left_w = seg[idx << 1].win[s0];
        int right_w = seg[idx << 1|1].win[s0];
        seg[idx].win[s0] = cmp_choose(left_w, right_w, comp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> n >> m)) return 0;

    baseVal.assign(n+1, 0);
    expVal.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int s; cin >> s;
        baseVal[i] = s;
        expVal[i] = 0;
    }

    seg.assign(4*n + 5, Node());
    build(1, 1, n);

    int rounds = __builtin_ctz(n); // k
    for (int war = 1; war <= m; war++) {
        int season;
        if (rounds % 2 == 0) season = 0;
        else season = ((war-1) & 1);

        int champion = seg[1].win[season];
        cout << champion << '\n';

        expVal[champion] += 1;
        update(1, 1, n, champion);
    }
    return 0;
}