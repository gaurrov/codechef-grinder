#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of length N.
 * We want to find the minimum non-negative integer X such that:
 * Sum(A_i + X) >= 0 for all i from 1 to N.
 * 
 * Expanding the sum:
 * Sum(A_i) + Sum(X) >= 0
 * Sum(A_i) + N * X >= 0
 * N * X >= -Sum(A_i)
 * X >= -Sum(A_i) / N
 * 
 * Since X must be a non-negative integer:
 * If Sum(A_i) >= 0, then X = 0 is sufficient.
 * If Sum(A_i) < 0, we need N * X >= |Sum(A_i)|.
 * X >= ceil(|Sum(A_i)| / N).
 * 
 * Using integer division, ceil(a / b) can be calculated as (a + b - 1) / b.
 */

void solve() {
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        sum += val;
    }

    if (sum >= 0) {
        cout << 0 << "\n";
    } else {
        long long abs_sum = -sum;
        // We need N * X >= abs_sum
        // X = ceil(abs_sum / N)
        long long x = (abs_sum + N - 1) / N;
        cout << x << "\n";
    }
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