#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N workers with salaries W_i.
 * An operation consists of choosing one worker and increasing everyone else's salary by 1.
 * This is equivalent to saying: the chosen worker's salary remains the same, 
 * while everyone else's salary increases by 1.
 * 
 * Let the target equal salary be S. Since we can only increase salaries, 
 * S must be at least the maximum initial salary.
 * However, notice that increasing everyone except worker i by 1 is equivalent 
 * to decreasing worker i's salary by 1 relative to the others.
 * 
 * If we perform the operation such that we always pick the worker with the 
 * current maximum salary to be the "loser", we effectively reduce the 
 * difference between the maximum and the minimum.
 * 
 * Mathematically, if we want to reach a state where all salaries are equal to 
 * the initial maximum value (let's call it max_w), the number of operations 
 * required for a worker with salary W_i is (W_i - min_w).
 * Summing this over all workers gives the total operations:
 * Total = Sum(W_i - min_w) for all i.
 * 
 * This is because each operation increases the sum of all salaries by (N-1).
 * To reach a state where all are equal to max_w, the total sum must be N * max_w.
 * The number of operations is (N * max_w - Sum(W_i)) / (N - 1).
 * This simplifies to Sum(W_i - min_w).
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_w = 20000; // Larger than max constraint 10000
    long long sum_w = 0;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_w) {
            min_w = w[i];
        }
        sum_w += w[i];
    }

    // The total number of operations is the sum of differences 
    // between each salary and the minimum salary.
    long long operations = 0;
    for (int i = 0; i < n; ++i) {
        operations += (w[i] - min_w);
    }

    cout << operations << "\n";
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