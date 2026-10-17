# [Two Different Palindromes (TWODIFFPALIN)](https://www.codechef.com/problems/TWODIFFPALIN)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we need to determine if it is possible to construct at least two distinct binary strings that are palindromes, such that each string contains exactly $A$ zeros and $B$ ones.

## Intuition & Mathematical Observation
To form a palindrome with a fixed number of zeros ($A$) and ones ($B$):

1.  **Parity Constraint**: 
    *   In any palindrome, if the total length $N = A + B$ is even, both $A$ and $B$ must be even.
    *   If the total length $N$ is odd, exactly one of $A$ or $B$ must be odd, and the other must be even.
    *   If both $A$ and $B$ are odd, the total length $A+B$ is even, but the counts are odd. This makes it impossible to form even a single palindrome. Thus, if $A \equiv 1 \pmod 2$ and $B \equiv 1 \pmod 2$, the answer is **"No"**.

2.  **Uniqueness Constraint**:
    *   If $A=1$ or $B=1$, the structure of the palindrome is highly restricted. For example, if $A=1$ and $B=4$, the only possible palindrome is `11011`. Because there is only one way to arrange the characters to satisfy the palindrome property, we cannot form *two* different palindromes. Thus, if $A=1$ or $B=1$, the answer is **"No"**.

3.  **General Case**:
    *   If neither of the above conditions is met (i.e., at least one count is even and both are greater than 1), we can always construct at least two distinct palindromes. For example, if $A=2, B=2$, we can form `0110` and `1001`. If $A=2, B=3$, we can form `01110` and `10101`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and conditional checks.
- **Space Complexity**: $O(1)$, as we use no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. If both A and B are odd, the total length (A+B) is even. 
 *    A palindrome of even length requires both counts to be even. 
 *    Therefore, it's impossible to form any palindrome.
 * 
 * 2. If A=1 or B=1, the placement of the single character is fixed 
 *    by the palindrome property, resulting in only one unique string.
 * 
 * 3. Otherwise, we can always construct at least two different palindromes.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // Condition 1: Both odd -> Impossible
    // Condition 2: Either is 1 -> Only one unique palindrome possible
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } 
    else {
        cout << "Yes" << "\n";
    }
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