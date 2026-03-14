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
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b) p[b]=a;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    unordered_map<string,int> id;
    id.reserve(2*n);

    vector<pair<int,int>> edges;

    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);

        int comma = line.find(',');
        string child = line.substr(0, comma);

        int pos = line.find("son of ");
        string father = line.substr(pos + 7);

        if(!id.count(child)) id[child] = id.size();
        if(!id.count(father)) id[father] = id.size();

        edges.push_back({id[child], id[father]});
    }

    DSU dsu(id.size());

    for(auto &e:edges)
        dsu.unite(e.first, e.second);

    int root = dsu.find(edges[0].first);

    for(auto &p:id){
        if(dsu.find(p.second) != root){
            cout << "impossible\n";
            return 0;
        }
    }

    cout << "possible\n";

    return 0;
}