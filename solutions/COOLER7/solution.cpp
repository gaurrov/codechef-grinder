#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To drop the temperature from T to T-1, it takes T minutes.
 * To go from N to M:
 * Step 1: N -> N-1 takes N minutes.
 * Step 2: N-1 -> N-2 takes N-1 minutes.
 * ...
 * Step k: (M+1) -> M takes M+1 minutes.
 * 
 * Total time = N + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic series sum:
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * Sum = (N - M) * (N + M + 1) / 2
 * 
 * Constraints: N <= 40, so the result will easily fit in a standard integer.
 * Using long long for safety.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // The sum of the arithmetic progression from (M+1) to N
        // Sum = (N - M) * (N + M + 1) / 2
        long long total_time = (n - m) * (n + m + 1) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}