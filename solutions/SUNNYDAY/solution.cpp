#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef goes to the picnic if the temperature X > 24.
 * Constraints: 1 <= T <= 100, 1 <= X <= 100.
 * Since X fits in a standard integer, 'int' is sufficient.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Check if temperature is strictly greater than 24
        if (x > 24) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}