#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three points (Chef, Head Server, Sous-Chef).
 * Let the points be P1, P2, P3.
 * Two points can communicate if the Euclidean distance between them is <= R.
 * This is equivalent to distance squared <= R^2.
 * We need to check if the graph formed by these 3 nodes is connected.
 * Since there are only 3 nodes, the graph is connected if:
 * 1. (P1-P2 connected AND P2-P3 connected) OR
 * 2. (P1-P2 connected AND P1-P3 connected) OR
 * 3. (P2-P3 connected AND P1-P3 connected)
 * Basically, at least two pairs must be connected for the whole set to be connected.
 */

typedef long long ll;

ll distSq(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    ll R;
    cin >> R;
    ll R2 = R * R;
    
    ll x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Calculate distances squared between all pairs
    ll d12 = distSq(x[0], y[0], x[1], y[1]);
    ll d23 = distSq(x[1], y[1], x[2], y[2]);
    ll d13 = distSq(x[0], y[0], x[2], y[2]);
    
    bool c12 = (d12 <= R2);
    bool c23 = (d23 <= R2);
    bool c13 = (d13 <= R2);
    
    // Check connectivity:
    // If we have at least two connections, all three can communicate.
    int count = 0;
    if (c12) count++;
    if (c23) count++;
    if (c13) count++;
    
    if (count >= 2) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}