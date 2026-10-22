#include <iostream>

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * 1. If we choose K indices to be fixed points, we are left with M = N - K elements.
 * 2. These M elements must form a derangement (a permutation with zero fixed points).
 * 3. A derangement of size M exists if and only if M != 1.
 *    - If M = 0, it is a valid derangement (the empty set).
 *    - If M = 1, it is impossible to have 0 fixed points.
 *    - If M >= 2, a derangement always exists.
 * 
 * Therefore, the condition is: N - K != 1.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        // If N - K == 1, we are forced to have at least one fixed point 
        // among the remaining elements, making it impossible to have exactly K.
        if (n - k == 1) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}