#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob play a game where they choose numbers a and b (1 <= a, b <= 5).
 * The sum S = a + b.
 * If S is odd, Alice wins.
 * If S is even, Bob wins.
 * 
 * Constraints:
 * T <= 1000
 * 1 <= a, b <= 5
 * Time complexity: O(T)
 * Space complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Calculate the sum
        int sum = a + b;
        
        // Check if sum is odd or even
        // If sum % 2 != 0, it is odd, Alice wins.
        // Otherwise, it is even, Bob wins.
        if (sum % 2 != 0) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}