# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we want to make it a palindrome. In one operation, we can choose any two indices $i$ and $j$ and flip the bits at these positions (i.e., $0 \to 1$ and $1 \to 0$). We need to find the minimum number of operations required to make the string a palindrome.

## Intuition & Mathematical Observation
A string is a palindrome if $A[i] == A[N-1-i]$ for all $0 \le i < N/2$. 

1. **Identify Mismatches**: We iterate through the first half of the string and compare $A[i]$ with its symmetric counterpart $A[N-1-i]$. Let `mismatches` be the count of pairs where $A[i] \neq A[N-1-i]$.
2. **Analyze Operations**:
   - If we have a mismatch pair $(A[i], A[N-1-i])$, we need to change one of them to match the other. 
   - One operation allows us to flip two bits. If we flip one bit in a mismatch pair, we resolve that mismatch.
   - If we have two mismatch pairs, we can resolve both in a single operation by flipping one bit from each pair such that they become matching.
   - Therefore, every two mismatch pairs can be resolved in 1 operation. If there is an odd number of mismatch pairs, the remaining one will require an additional operation.
3. **Formula**: The total number of operations required is $\lceil \text{mismatches} / 2 \rceil$, which can be calculated using integer division as `(mismatches + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we iterate through half of the string once.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let 'mismatches' be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * Each operation can fix up to two mismatch pairs.
 * Thus, the minimum operations required is ceil(mismatches / 2.0).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int mismatches = 0;
    // Iterate through the first half of the string
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            mismatches++;
        }
    }

    // Each operation can resolve two mismatches.
    // The formula (mismatches + 1) / 2 performs ceiling division.
    cout << (mismatches + 1) / 2 << "\n";
}

int main() {
    // Optimize I/O operations
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