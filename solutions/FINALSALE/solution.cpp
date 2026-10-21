#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N days with projected sales A_1, A_2, ..., A_N.
 * If Chef closes the shop on day k (1 <= k <= N), the total sales will be:
 * Total = (A_1 + A_2 + ... + A_{k-1}) + (2 * A_k)
 * Total = (A_1 + A_2 + ... + A_k) + A_k
 * 
 * To maximize this, we need to calculate the prefix sum of the array A,
 * and for each possible closing day k, compute (PrefixSum[k] + A_k).
 * 
 * Constraints:
 * N <= 3*10^5, sum of N <= 3*10^5.
 * A_i <= 10^9.
 * The total sum can exceed 2^31 - 1, so we must use long long.
 * Time complexity: O(N) per test case, which is optimal.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long current_prefix_sum = 0;
    long long max_sales = 0;
    
    for (int i = 0; i < N; ++i) {
        current_prefix_sum += A[i];
        // If we close on day i (0-indexed), total is prefix_sum + A[i]
        long long current_total = current_prefix_sum + A[i];
        if (i == 0) {
            max_sales = current_total;
        } else {
            if (current_total > max_sales) {
                max_sales = current_total;
            }
        }
    }
    
    cout << max_sales << "\n";
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