# [Opposite Attract (P2169)](https://www.codechef.com/problems/P2169)

- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we need to construct a new string $T$ of the same length such that for every index $i$, the character $T[i]$ is different from $S[i]$. Since the string only contains '0' and '1', this means we must flip every bit in the string.

## Intuition & Mathematical Observation
The problem states that $T[i] \neq S[i]$. In a binary system:
- If $S[i] = '0'$, then $T[i]$ must be '1'.
- If $S[i] = '1'$, then $T[i]$ must be '0'.

This is a simple bitwise inversion. We can iterate through the input string $S$ and append the opposite character to a new string $T$ (or modify the string in place). Given the constraints, a simple linear scan $O(N)$ is optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. The total time complexity is $O(\sum N)$, which fits well within the 1-second time limit for the given constraints.
- **Space Complexity**: $O(N)$ to store the resulting string $T$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We need to construct a string T such that T[i] != S[i] for all i.
 * Since S consists only of '0' and '1':
 * - If S[i] == '0', then T[i] must be '1'.
 * - If S[i] == '1', then T[i] must be '0'.
 * This is equivalent to flipping each bit of the string.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    string T = "";
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            T += '1';
        } else {
            T += '0';
        }
    }
    cout << T << "\n";
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