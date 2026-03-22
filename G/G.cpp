#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    
}

struct DSU {
    vector<int> p, r;
    DSU(int n) { 
        p.resize(n); 
        iota(p.begin(), p.end(), 0); 
        r.assign(n, 0); 
    }
    int find(int x) { 
        return p[x] == x ? x : p[x] = find(p[x]); 
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<pair<string,string>> relations(n);
    unordered_map<string, vector<int>> name_to_rel;

    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        int comma = line.find(',');
        string child = line.substr(0, comma);

        int pos = line.find("son of ");
        string father = line.substr(pos + 7);

        relations[i] = {child, father};

        name_to_rel[child].push_back(i);
        name_to_rel[father].push_back(i);
    }

    DSU dsu(n);

    // unite all relations that share a name
    for(auto &[name, vec] : name_to_rel) {
        for(int i = 1; i < vec.size(); i++) {
            dsu.unite(vec[0], vec[i]);
        }
    }

    // check if all relations are in one component
    int root = dsu.find(0);
    bool possible = true;
    for(int i = 1; i < n; i++) {
        if(dsu.find(i) != root) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "possible" : "impossible") << "\n";
    return 0;
}