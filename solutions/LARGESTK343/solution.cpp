#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to arrange them such that there are at least K ones between any two zeros.
 * 
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let the number of ones in each gap be g_1, g_2, ..., g_{X-1}.
 * The condition is that each g_i >= K.
 * The total number of ones used in these gaps is sum(g_i) >= (X - 1) * K.
 * 
 * We also have ones that can be placed before the first zero and after the last zero.
 * However, the problem states "between any two occurrences of 0s".
 * This means the ones placed before the first zero or after the last zero do not 
 * contribute to the "between" constraint.
 * 
 * To maximize K, we should put all Y ones into the (X - 1) gaps.
 * So, Y >= (X - 1) * K.
 * Therefore, K <= Y / (X - 1).
 * 
 * Since we want the largest integer K, K = floor(Y / (X - 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X zeros create (X - 1) gaps between them.
        // We need at least K ones in each of these (X - 1) gaps.
        // Total ones required = (X - 1) * K <= Y.
        // K <= Y / (X - 1).
        
        long long K = Y / (X - 1);
        cout << K << "\n";
    }

    return 0;
}