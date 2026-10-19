#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total slippers = N
 * Left slippers = L
 * Right slippers = R = N - L
 * A pair consists of one left and one right slipper.
 * The number of pairs that can be formed is limited by the minimum of the 
 * number of left slippers and the number of right slippers.
 * Pairs = min(L, N - L)
 * Total revenue = Pairs * X
 * 
 * Constraints:
 * N, L, X <= 1000.
 * The result can be up to 1000 * 1000 = 1,000,000, which fits in a standard 32-bit int,
 * but using long long is safer practice in competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, l, x;
        cin >> n >> l >> x;

        // Calculate number of right slippers
        long long r = n - l;

        // The number of pairs is the minimum of left and right slippers
        long long pairs = min(l, r);

        // Calculate total revenue
        long long revenue = pairs * x;

        // Output the result
        cout << revenue << "\n";
    }

    return 0;
}