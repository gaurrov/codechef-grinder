#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees total.
 * Chef sold M trees for B rupees total.
 * The problem description says: "He bought N trees for A rupees, and then sold M trees for B rupees."
 * The sample explanation clarifies: "Chef bought 5 trees for 100 rupees, and then sold 2 trees for 1000 rupees, 
 * thus his profit was 2000 - 500 = 1500 rupees."
 * 
 * Wait, let's re-read the sample explanation carefully:
 * Input: 5 100 2 1000
 * Output: 1500
 * Explanation: "Chef bought 5 trees for 100 rupees [each], and then sold 2 trees for 1000 rupees [each], 
 * thus his profit was (2 * 1000) - (5 * 100) = 2000 - 500 = 1500."
 * 
 * Input: 5 100 2 100
 * Output: -300
 * Explanation: (2 * 100) - (5 * 100) = 200 - 500 = -300.
 * 
 * Formula: Profit = (M * B) - (N * A)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but the instructions mention handling multiple test cases. 
    // Given the constraints and typical competitive programming patterns:
    
    long long N, A, M, B;
    if (cin >> N >> A >> M >> B) {
        long long profit = (M * B) - (N * A);
        cout << profit << "\n";
    }

    return 0;
}