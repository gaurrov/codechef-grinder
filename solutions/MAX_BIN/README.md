# [Max Binary (MAX_BIN)](https://www.codechef.com/problems/MAX_BIN)

- **Difficulty Rating**: 1143
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, you are allowed to perform two types of operations:
1. **Type 1**: Append a '0' to the end of the string.
2. **Type 2**: Change any '0' in the string to a '1'.

You have exactly $K$ operations to perform. The goal is to maximize the decimal value of the resulting binary string.

## Intuition & Mathematical Observation
To maximize the value of a binary number, we must prioritize the most significant bits (the leftmost bits).

1. **Prioritizing the Leading Bit**: If the string starts with '0', changing it to '1' (Type 2 operation) increases the value significantly because it adds $2^{N-1}$ to the total value. This is always more beneficial than changing any other '0' to a '1' later in the string.
2. **Maximizing Length**: Appending a '0' to the end (Type 1 operation) effectively shifts all existing bits to the left, multiplying the current value by 2. Since we want the largest possible number, increasing the length of the string is highly effective.
3. **Strategy**:
    - If $S[0] == '0'$, use one operation to flip it to '1'. This costs 1 operation.
    - Use all remaining $K$ operations to append '0's to the end of the string. This maximizes the power of 2 by which the existing binary number is multiplied.

## Complexity Analysis
- **Time Complexity**: $O(N + K)$, where $N$ is the length of the string and $K$ is the number of operations. We iterate through the string once and print $K$ zeros.
- **Space Complexity**: $O(N)$, as we store the input string in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the decimal value of a binary string:
 * 1. The most significant bit (the leftmost bit) has the highest impact.
 * 2. If the first character is '0', changing it to '1' (Type 2 operation) is the 
 *    most effective way to increase the value.
 * 3. Adding '0's at the end (Type 1 operation) shifts all existing bits to the 
 *    left, effectively multiplying the current value by 2^k.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // If the first bit is '0', we should change it to '1' first.
    // This costs 1 operation.
    if (S[0] == '0') {
        S[0] = '1';
        K--;
    }

    // After ensuring the first bit is '1' (if possible), 
    // any remaining operations should be used to append '0's at the end.
    // Appending '0' at the end is equivalent to multiplying by 2,
    // which is always better than changing internal '0's to '1's 
    // because it increases the power of all existing bits.
    
    cout << S;
    for (int i = 0; i < K; ++i) {
        cout << '0';
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```