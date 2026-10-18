#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has budget Y, membership cost X.
 * Each trial session costs 1 coin.
 * After n trial sessions:
 * - Remaining budget: Y - n
 * - Discount: n * D %
 * - Membership price: X * (1 - (n * D) / 100)
 * 
 * We need to find the smallest n >= 0 such that:
 * (Y - n) >= X * (100 - n * D) / 100
 * 
 * Multiplying by 100 to avoid floating point issues:
 * 100 * (Y - n) >= X * (100 - n * D)
 * 
 * Constraints are very small (X <= 50), so we can iterate n from 0 to Y.
 * If no n satisfies the condition, output -1.
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // If Chef can already afford it without any sessions
    if (Y >= X) {
        cout << 0 << "\n";
        return;
    }

    // Iterate through possible number of sessions.
    // Chef cannot take more than Y sessions because he would have 0 coins left.
    for (int n = 1; n <= Y; ++n) {
        // Remaining budget after n sessions
        int remaining_budget = Y - n;
        
        // Discounted price: X * (100 - n * D) / 100
        // We check: remaining_budget * 100 >= X * (100 - n * D)
        if (remaining_budget * 100 >= X * (100 - n * D)) {
            cout << n << "\n";
            return;
        }
    }

    // If no n works
    cout << -1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}