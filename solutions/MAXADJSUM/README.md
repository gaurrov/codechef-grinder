# [Maximise Adjacent Sum (MAXADJSUM)](https://www.codechef.com/problems/MAXADJSUM)

- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to rearrange the elements to maximize the sum of adjacent elements:
$$f(A) = \sum_{i=1}^{N-1} (A_i + A_{i+1})$$

## Intuition & Mathematical Observation
By expanding the summation, we observe the frequency of each element in the final sum:
$$f(A) = (A_1 + A_2) + (A_2 + A_3) + \dots + (A_{N-1} + A_N)$$
$$f(A) = A_1 + 2A_2 + 2A_3 + \dots + 2A_{N-1} + A_N$$

From this expansion, it is clear that:
1. The elements at the ends ($A_1$ and $A_N$) are counted exactly **once**.
2. All internal elements ($A_2$ through $A_{N-1}$) are counted **twice**.

To maximize the total sum, we want the largest possible values to be multiplied by 2. Conversely, we want the smallest possible values to be placed at the ends (where they are only counted once). 

If we sort the array such that $S_1 \le S_2 \le \dots \le S_N$, the optimal strategy is to place $S_1$ and $S_2$ at the ends. The resulting maximum sum is:
$$\text{Sum} = 2 \times \sum_{i=1}^{N} S_i - (S_1 + S_2)$$

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The summation and calculation steps are $O(N)$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N)
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * 
 * To maximize this sum, we want the largest elements to have a coefficient of 2.
 * The two smallest elements should be placed at the ends (A_1 and A_N) so that 
 * they are only counted once. All other elements will be counted twice.
 * 
 * Let the sorted array be S_1 <= S_2 <= ... <= S_N.
 * The maximum sum is:
 * S_1 + S_N + 2 * (S_2 + S_3 + ... + S_{N-1})
 * 
 * This can be rewritten as:
 * 2 * (sum of all elements) - (S_1 + S_2)
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    // Sort to easily identify the two smallest elements
    sort(A.begin(), A.end());

    // The two smallest elements are A[0] and A[1].
    // To maximize the sum, we place the two smallest elements at the ends.
    // The sum is 2 * (sum of all) - (A[0] + A[1]).
    
    long long result = 2 * total_sum - (A[0] + A[1]);
    cout << result << "\n";
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