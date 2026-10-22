# [Alternating Array (ALTARR)](https://www.codechef.com/problems/ALTARR)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the minimum number of elements to change such that the array becomes "alternating." An array is alternating if the parity (even or odd) of any two adjacent elements is different.

## Intuition & Mathematical Observation
An alternating array must follow one of two possible parity patterns:
1. **Pattern 1**: Starts with an Odd number (Odd, Even, Odd, Even, ...).
2. **Pattern 2**: Starts with an Even number (Even, Odd, Even, Odd, ...).

For any given array, we can calculate the cost (number of changes required) to transform it into Pattern 1 and the cost to transform it into Pattern 2. 
- For **Pattern 1**, at index $i$, the expected parity is $1$ if $i$ is even and $0$ if $i$ is odd.
- For **Pattern 2**, at index $i$, the expected parity is $0$ if $i$ is even and $1$ if $i$ is odd.

By iterating through the array once and comparing the actual parity of $A[i]$ against these two patterns, we can count the mismatches. The final answer is simply the minimum of these two counts.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to compare parities.
- **Space Complexity**: $O(N)$ to store the array, though this could be optimized to $O(1)$ by processing elements on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of A[i] is different from A[i+1].
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Odd, Even, Odd, Even, ...
 * Pattern 2: Even, Odd, Even, Odd, ...
 * 
 * To find the minimum changes, we count how many elements in the original array
 * violate Pattern 1 and how many violate Pattern 2. The answer is the minimum
 * of these two counts.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: changes needed for Pattern 1 (Odd at index 0)
    // count2: changes needed for Pattern 2 (Even at index 0)
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2; // 1 for odd, 0 for even
        
        // Pattern 1: index 0 is odd (1), index 1 is even (0), index 2 is odd (1)...
        // Expected parity at index i is (i % 2 == 0 ? 1 : 0)
        int expected1 = (i % 2 == 0 ? 1 : 0);
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: index 0 is even (0), index 1 is odd (1), index 2 is even (0)...
        // Expected parity at index i is (i % 2 == 0 ? 0 : 1)
        int expected2 = (i % 2 == 0 ? 0 : 1);
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```