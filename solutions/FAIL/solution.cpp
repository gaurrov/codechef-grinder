#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef takes N tests. We need to check if the average after every test i (1 to N)
 * is at least 40.
 * Average after i tests = (Sum of marks from 1 to i) / i.
 * Condition: (Sum of marks from 1 to i) / i >= 40
 * Which is equivalent to: (Sum of marks from 1 to i) >= 40 * i.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= 100.
 * The sum will not exceed 100 * 100 = 10,000, which fits in a standard int.
 */

void solve() {
    int N;
    cin >> N;
    
    long long current_sum = 0;
    bool possible = true;
    
    for (int i = 1; i <= N; ++i) {
        int marks;
        cin >> marks;
        current_sum += marks;
        
        // Check if average is >= 40
        // Average = current_sum / i
        // Condition: current_sum / i >= 40  => current_sum >= 40 * i
        if (current_sum < 40LL * i) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}