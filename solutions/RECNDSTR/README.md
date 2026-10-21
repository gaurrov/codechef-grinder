# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we define two operations:
1. **Left Shift $L(S)$**: Move the first character of the string to the end.
2. **Right Shift $R(S)$**: Move the last character of the string to the beginning.

We need to determine if there exists a string $V$ such that $L(V) = S$ and $R(V) = S$. Essentially, we are checking if the string $S$ can be transformed into itself by both a left shift and a right shift.

## Intuition & Mathematical Observation
The problem asks if there exists a $V$ such that $L(V) = S$ and $R(V) = S$. 
- If we perform a left shift on $S$, we get $L(S)$.
- If we perform a right shift on $S$, we get $R(S)$.

The condition $L(V) = S$ implies that $V$ is the string $S$ shifted **right** by one position.
The condition $R(V) = S$ implies that $V$ is the string $S$ shifted **left** by one position.

Therefore, the problem reduces to checking if the left shift of $S$ is equal to the right shift of $S$ ($L(S) == R(S)$). 

**Edge Case:**
For strings with length $N \le 2$, any shift results in the same string or a trivial permutation that satisfies the condition, so we can immediately output "YES".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform string slicing and concatenation, which takes linear time relative to the length of the string.
- **Space Complexity**: $O(N)$ to store the shifted versions of the string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length N.
 * L(V) = S implies V[1...N-1] + V[0] = S[0...N-1]
 * This means V[i] = S[(i+1) % N]
 * R(V) = S implies V[N-1] + V[0...N-2] = S[0...N-1]
 * This means V[i] = S[(i-1+N) % N]
 * 
 * Combining these, we need to check if shifting S left by 1 is the same as 
 * shifting S right by 1.
 * Specifically, if we shift S left by 1 to get L(S), and shift S right by 1 
 * to get R(S), the condition L(V) = S and R(V) = S is equivalent to 
 * checking if L(S) == R(S).
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // For strings of length <= 2, the condition is always satisfied.
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Left shift L(S): move first char to end
    string l_s = s.substr(1) + s[0];
    
    // Right shift R(S): move last char to beginning
    string r_s = s[n - 1] + s.substr(0, n - 1);
    
    if (l_s == r_s) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
```