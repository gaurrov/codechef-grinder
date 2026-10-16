#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Arya starts at (X0, Y0) and can jump exactly L units in 4 directions.
 * This means Arya can reach any cell (x, y) such that:
 * x = X0 + k1 * L, where 1 <= x <= N
 * y = Y0 + k2 * L, where 1 <= y <= M
 * 
 * Since the movement is independent in the X and Y dimensions, the set of 
 * reachable cells is the Cartesian product of reachable rows and reachable columns.
 * 
 * Reachable rows:
 * The set of rows is {X0 + k*L | 1 <= X0 + k*L <= N}.
 * This is an arithmetic progression with common difference L.
 * The number of such rows is:
 * (Max reachable row - Min reachable row) / L + 1
 * Min reachable row: X0 - floor((X0 - 1) / L) * L
 * Max reachable row: X0 + floor((N - X0) / L) * L
 * Number of rows = ((Max - Min) / L) + 1
 * 
 * Similarly for columns:
 * Min reachable col: Y0 - floor((Y0 - 1) / L) * L
 * Max reachable col: Y0 + floor((M - Y0) / L) * L
 * Number of cols = ((Max - Min) / L) + 1
 * 
 * Total reachable cells = (Number of rows) * (Number of columns)
 */

void solve() {
    long long N, M, X0, Y0, L;
    if (!(cin >> N >> M >> X0 >> Y0 >> L)) return;

    // Calculate number of reachable rows
    // Arya can reach row r if (r - X0) is a multiple of L
    // r = X0 + k*L. 
    // Smallest r >= 1: X0 - ((X0 - 1) / L) * L
    // Largest r <= N: X0 + ((N - X0) / L) * L
    
    long long min_r = X0 - ((X0 - 1) / L) * L;
    long long max_r = X0 + ((N - X0) / L) * L;
    long long count_r = (max_r - min_r) / L + 1;

    // Calculate number of reachable columns
    long long min_c = Y0 - ((Y0 - 1) / L) * L;
    long long max_c = Y0 + ((M - Y0) / L) * L;
    long long count_c = (max_c - min_c) / L + 1;

    cout << count_r * count_c << "\n";
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