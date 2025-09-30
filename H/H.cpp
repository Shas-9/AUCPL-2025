#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double r;
    if (!(cin >> n >> r)) return 0;
    vector<pair<double,double>> centers(n);
    for (int i = 0; i < n; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        centers[i] = {double(xi), double(yi)};
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    vector<int> unique_angles;
    vector<char> seen(360, 0);
    for (int i = 0; i < q; ++i) {
        int th;
        cin >> th;
        if (th < 0) th = (th%360 + 360) % 360;
        queries[i] = th;
        if (!seen[th]) {
            seen[th] = 1;
            unique_angles.push_back(th);
        }
    }

    const double EPS = 1e-12;
    // precompute cos and sin for all 360 integer degrees
    vector<double> cosv(360), sinv(360);
    const double PI = acos(-1.0);
    for (int deg = 0; deg < 360; ++deg) {
        double rad = deg * PI / 180.0;
        cosv[deg] = cos(rad);
        sinv[deg] = sin(rad);
    }

    // precompute c2 for centers: |C|^2 - r^2
    vector<double> c2(n);
    for (int i = 0; i < n; ++i) {
        double x = centers[i].first, y = centers[i].second;
        c2[i] = x*x + y*y - r*r;
        // c2 > 0 guaranteed by problem (no bumper intersects origin).
    }

    // Map angle -> minimal distance or INF for MISS
    const double INF = 1e50;
    vector<double> best(360, INF);

    for (int ang : unique_angles) {
        double cx = cosv[ang], cy = sinv[ang];
        double mn = INF;
        for (int i = 0; i < n; ++i) {
            double x = centers[i].first, y = centers[i].second;
            double p = x*cx + y*cy; // projection
            if (p <= 0.0) continue; // circle is behind or orthogonal; no forward intersection
            double disc = p*p - c2[i];
            if (disc < -EPS) continue;
            if (disc < 0.0) disc = 0.0;
            double delta = sqrt(disc);
            double s = p - delta; // first intersection (>=0)
            if (s < -EPS) continue;
            if (s < mn) mn = s;
        }
        best[ang] = mn;
    }

    cout.setf(std::ios::fixed); cout<<setprecision(4);
    for (int th : queries) {
        if (best[th] >= INF/2) {
            cout << "MISS\n";
        } else {
            cout << "HIT " << best[th] << '\n';
        }
    }

    return 0;
}