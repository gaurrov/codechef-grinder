# [Processing a string (KOL15A)](https://www.codechef.com/problems/KOL15A)

- **Difficulty Rating**: 1125
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ containing both uppercase English letters and digits (0-9), the task is to calculate the sum of all the individual digits present in the string.

## Intuition & Mathematical Observation
The problem requires us to parse a string and extract numerical values. Since the input consists of characters, we can iterate through the string character by character. 

1. **Identification**: We check if a character is a digit using the `isdigit()` function (or by checking if the character falls within the ASCII range of '0' to '9').
2. **Conversion**: In C++, characters are represented by their ASCII values. The digit characters '0' through '9' are stored contiguously. Therefore, to convert a character digit `c` to its integer equivalent, we can simply perform the operation `c - '0'`.
3. **Accumulation**: We maintain a running sum variable and add the converted integer value to it whenever a digit is encountered.

## Complexity Analysis
- **Time Complexity**: $O(T \times |S|)$, where $T$ is the number of test cases and $|S|$ is the length of the string. We perform a single pass over each string.
- **Space Complexity**: $O(|S|)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Processing a string (KOL15A)
 * Approach: Iterate through each character of the string. If the character is a digit
 * (checked via isdigit()), convert it to its integer value and add it to the running sum.
 */

void solve() {
    string s;
    cin >> s;
    
    long long sum = 0;
    for (char c : s) {
        // Check if the character is a digit '0'-'9'
        if (isdigit(c)) {
            // Convert char digit to int by subtracting the ASCII value of '0'
            sum += (c - '0');
        }
    }
    cout << sum << "\n";
}

int main() {
    // Fast I/O setup for performance
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