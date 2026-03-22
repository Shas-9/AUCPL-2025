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

struct Ingredient {
    string name;
    double percent;
};

int main() {
    int n;
    cin >> n;
    vector<Ingredient> ingredients(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ingredients[i].name;
        if (cin.peek() != '\n') {
            double p;
            cin >> p;
            ingredients[i].percent = p;
        } else {
            ingredients[i].percent = -1;
        }
    }

    double totalSpecified = 0;
    int unspecifiedCount = 0;
    for (auto &ing : ingredients) {
        if (ing.percent >= 0) totalSpecified += ing.percent;
        else unspecifiedCount++;
    }

    // Compute min and max for unspecified
    vector<pair<double, double>> results;
    double remaining = 100 - totalSpecified;

    for (int i = 0; i < n; i++) {
        if (ingredients[i].percent >= 0) continue;

        double minP = 0;

        double maxP = remaining;
        if (i > 0 && ingredients[i-1].percent >= 0) {
            maxP = min(maxP, ingredients[i-1].percent);
        }

        results.push_back({minP, maxP});

        // reduce remaining by min for next ingredient
        remaining -= minP;
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (ingredients[i].percent >= 0) continue;
        cout << fixed << setprecision(9);
        cout << ingredients[i].name << " " << results[idx].first << " " << results[idx].second << "\n";
        idx++;
    }

    return 0;
}