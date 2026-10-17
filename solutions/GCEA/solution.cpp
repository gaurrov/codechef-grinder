#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon i with difficulty A_i:
 * - Cost using Normal Pekóballs: A_i * X
 * - Cost using a Master Pekóball: Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum
 * of (A_i * X) and Y.
 * 
 * Total Cost = Sum_{i=1 to N} min(A_i * X, Y)
 * 
 * Constraints:
 * N, X, Y, A_i <= 100.
 * The maximum possible cost is 100 * 100 * 100 = 1,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long
 * is good practice to prevent overflow in competitive programming.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        // For each Pekómon, pick the cheaper option
        total_cost += min((long long)A[i] * X, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}