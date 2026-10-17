#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The battle mechanism describes an XOR operation.
 * When two contestants battle, if both have a weapon of type j, it is destroyed.
 * This is equivalent to: (1 XOR 1) = 0.
 * If one has it and the other doesn't, the winner keeps it: (1 XOR 0) = 1.
 * If neither has it, the winner doesn't have it: (0 XOR 0) = 0.
 * 
 * Since the XOR operation is associative and commutative, the final set of 
 * weapons the winner has is simply the XOR sum of all initial weapon strings.
 * The order of battles does not matter.
 * 
 * Complexity:
 * Time: O(T * N * L), where L = 10 (length of string).
 * Space: O(L) to store the running XOR sum.
 */

void solve() {
    int N;
    cin >> N;
    
    // We can represent the 10-bit string as an integer since 2^10 = 1024.
    int final_xor = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer
        int current_val = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_val |= (1 << (9 - j));
            }
        }
        
        // XOR the current contestant's weapons into the total
        final_xor ^= current_val;
    }
    
    // Count the number of set bits (1s) in the final XOR result
    int weapon_count = 0;
    for (int j = 0; j < 10; ++j) {
        if ((final_xor >> j) & 1) {
            weapon_count++;
        }
    }
    
    cout << weapon_count << "\n";
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