#include <iostream>

/**
 * Problem Analysis:
 * Given L and R, we need to print all odd numbers in the range [L, R] inclusive.
 * 
 * Approach:
 * 1. Start from L.
 * 2. If L is even, increment to L+1 to get the first odd number.
 * 3. Iterate from that starting point up to R, incrementing by 2 in each step.
 * 4. Print each number followed by a space.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int L, R;
    if (!(std::cin >> L >> R)) return 0;

    // Find the first odd number >= L
    int start = (L % 2 != 0) ? L : L + 1;

    // Print all odd numbers up to R
    bool first = true;
    for (int i = start; i <= R; i += 2) {
        if (!first) {
            std::cout << " ";
        }
        std::cout << i;
        first = false;
    }
    std::cout << std::endl;

    return 0;
}