#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let a subset of legs have strengths {S_1, S_2, ..., S_k}.
 * Let the minimum strength in this subset be S_min.
 * If we use these k legs, the weight W must satisfy:
 * W / k <= S_min  => W <= k * S_min.
 * To maximize W for a fixed subset, we should choose W = k * S_min.
 * 
 * To maximize this over all possible subsets:
 * 1. Sort the strengths in non-decreasing order: W_1 <= W_2 <= ... <= W_N.
 * 2. If we decide that the minimum strength in our subset is W_i, 
 *    then to maximize the weight, we should include all legs with strength >= W_i.
 * 3. The number of such legs is (N - i + 1).
 * 4. The maximum weight for this choice is (N - i + 1) * W_i.
 * 5. We iterate through all i from 0 to N-1 and find the maximum of these values.
 * 
 * Time Complexity: O(N log N) per test case due to sorting.
 * Space Complexity: O(N) to store the weights.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the weights to easily count how many legs have strength >= W_i
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    
    // For each leg i, if it is the minimum strength leg in our subset,
    // we can include all legs from i to n-1.
    // The number of such legs is (n - i).
    for (int i = 0; i < n; ++i) {
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
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