#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sells for 3 coins individually.
 * A bundle of (1R, 1B, 1G) sells for 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 *             = 10k + 3(R + B + G - 3k)
 *             = 10k + 3(R + B + G) - 9k
 *             = k + 3(R + B + G)
 * 
 * To maximize this, we need to maximize k.
 * Therefore, k = min(R, min(B, G)).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, b, g;
        cin >> r >> b >> g;

        // Calculate maximum number of bundles possible
        long long k = min({r, b, g});

        // Calculate total coins
        // Formula: k * 10 + (remaining gems) * 3
        long long remaining_gems = (r - k) + (b - k) + (g - k);
        long long total_coins = (k * 10) + (remaining_gems * 3);

        cout << total_coins << "\n";
    }

    return 0;
}