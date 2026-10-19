# [Encoded String (DECODEIT)](https://www.codechef.com/problems/DECODEIT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to decode a string of length $N$ (where $N$ is a multiple of 4) consisting of '0's and '1's. The string is formed by concatenating 4-bit binary representations of the first 16 lowercase English letters ('a' through 'p'). Specifically, 'a' corresponds to `0000` (0), 'b' to `0001` (1), ..., and 'p' to `1111` (15). We need to partition the input string into 4-bit segments, convert each segment to its decimal equivalent, and map it to the corresponding character.

## Intuition & Mathematical Observation
The encoding scheme is a direct mapping of a 4-bit binary number to an index in the alphabet. Since there are $2^4 = 16$ possible combinations for a 4-bit string, each segment maps uniquely to one of the first 16 letters of the alphabet.

- **Conversion**: A 4-bit binary string $b_0b_1b_2b_3$ can be converted to an integer using the formula:
  $$\text{value} = b_0 \cdot 2^3 + b_1 \cdot 2^2 + b_2 \cdot 2^1 + b_3 \cdot 2^0$$
- **Mapping**: Once the integer value (0–15) is obtained, the character is simply `'a' + value`.
- **Implementation**: We can process the string in chunks of 4 using a loop. For each chunk, we use bitwise operations (`val << 1 | bit`) to efficiently calculate the decimal value.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the input string. We iterate through the string exactly once, performing constant-time operations for each 4-bit segment.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the resulting decoded string (or print characters on the fly), which does not depend on the input size beyond the output requirement.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem describes a binary encoding scheme for the first 16 lowercase English letters (a-p).
 * Each character is represented by a 4-bit binary string.
 * This is equivalent to interpreting the 4-bit string as an integer from 0 to 15,
 * where 0000 corresponds to 'a' (index 0) and 1111 corresponds to 'p' (index 15).
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Iterate through the string in chunks of 4 bits
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
```