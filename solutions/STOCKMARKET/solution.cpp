#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days of profit/loss. We need to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - (A_i that we skip).
 * To maximize the total profit, we need to minimize the value of the day we skip.
 * Therefore, the strategy is:
 * 1. Calculate the sum of all elements in the array.
 * 2. Find the minimum element in the array.
 * 3. The result is (Sum - Minimum Element).
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of days.
 * Space: O(1) auxiliary space (if we process elements on the fly).
 */

void solve() {
    int N;
    cin >> N;
    
    long long total_sum = 0;
    int min_val = 101; // Since constraints say A_i <= 100
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        total_sum += val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // We skip the day with the minimum profit (or maximum loss)
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}