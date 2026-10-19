#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem describes a binary encoding scheme for the first 16 lowercase English letters (a-p).
 * Each character is represented by a 4-bit binary string.
 * This is equivalent to interpreting the 4-bit string as an integer from 0 to 15,
 * where 0000 corresponds to 'a' (index 0) and 1111 corresponds to 'p' (index 15).
 * 
 * Algorithm:
 * 1. Iterate through the string in chunks of 4 bits.
 * 2. Convert each 4-bit substring into its decimal integer representation.
 * 3. Map the integer (0-15) to the corresponding character ('a' + integer).
 * 4. Print the resulting characters.
 * 
 * Complexity:
 * Time Complexity: O(N), where N is the length of the string. We process each bit once.
 * Space Complexity: O(1) auxiliary space (excluding the input/output storage).
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary string to integer
        // Bit 0 is most significant, Bit 3 is least significant
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) | (s[i + j] - '0');
        }
        // Map 0-15 to 'a'-'p'
        result += (char)('a' + val);
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}