#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * The total cost is the sum of (A_i * i) for i from 1 to N.
 * Constraints: T <= 100, N <= 100, A_i <= 100.
 * Max possible cost = 100 * (100 * 100) = 1,000,000, which fits in a standard int.
 * The previous TLE was likely due to environment-specific I/O behavior.
 * Using standard cin/cout with fast I/O is the correct approach.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        int A_i;
        cin >> A_i;
        // The i-th colour balloon costs i rupees.
        // We bought A_i balloons of this colour.
        total_cost += (long long)A_i * i;
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}