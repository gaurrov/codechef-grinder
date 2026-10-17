# [Convert to permutation (PERMUTATION)](https://www.codechef.com/problems/PERMUTATION)

- **Difficulty Rating**: 1197
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to transform it into a permutation of $\{1, 2, \dots, N\}$ using only increment operations. Each increment operation increases an element by 1. We want to find the minimum number of operations required to achieve this, or determine if it is impossible.

## Intuition & Mathematical Observation
1. **Sorting**: To minimize the total number of operations, we should sort the array $A$ in non-decreasing order. By sorting, we align the smallest elements of the input array with the smallest required values of the target permutation $\{1, 2, \dots, N\}$.
2. **Constraint Check**: Since we can only **increase** values, an element $A[i]$ (in the sorted array) can only be transformed into a target value $T$ if $A[i] \le T$. If $A[i] > (i + 1)$, it is impossible to transform $A[i]$ into $(i + 1)$ because we cannot decrease the value. In such a case, we output $-1$.
3. **Greedy Strategy**: After sorting, the $i$-th element (0-indexed) must be transformed into $(i + 1)$. The cost for this specific transformation is $(i + 1) - A[i]$. Summing these costs for all $i$ from $0$ to $N-1$ gives the minimum total operations.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and we want to transform it into a permutation
 * of {1, 2, ..., N} using only increment operations.
 * 
 * 1. Since we can only increase elements, if an element A[i] is already greater 
 *    than N, it is impossible to make it part of a permutation of size N.
 * 2. To minimize the total number of operations, we should sort the array A first.
 *    Let the sorted array be A'.
 * 3. After sorting, we want to map each A'[i] to a unique value in {1, 2, ..., N}.
 *    The optimal strategy is to map the smallest elements of A' to the smallest 
 *    available values in the permutation.
 * 4. Specifically, if A'[i] > (i + 1), it is impossible to reach the value (i + 1)
 *    because we can only increase values. If A'[i] <= (i + 1), the cost to 
 *    transform A'[i] to (i + 1) is (i + 1) - A'[i].
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to align with the target permutation {1, 2, ..., N}
    sort(A.begin(), A.end());

    long long operations = 0;
    for (int i = 0; i < N; ++i) {
        // The target value for the i-th smallest element is (i + 1)
        // If the current element is already larger than the target, transformation is impossible
        if (A[i] > (i + 1)) {
            cout << -1 << "\n";
            return;
        }
        operations += ((i + 1) - A[i]);
    }

    cout << operations << "\n";
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