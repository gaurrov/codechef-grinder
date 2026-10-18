# [Easy Permutation (EASYPERM)](https://www.codechef.com/problems/EASYPERM)

- **Difficulty Rating**: 1057
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A$ of the set $\{1, 2, \dots, N\}$ such that the Least Common Multiple (LCM) of the sequence $S = \{1+A_1, 2+A_2, \dots, N+A_N\}$ is minimized.

## Intuition & Mathematical Observation
Let $B_i = i + A_i$. We are looking to minimize $\text{LCM}(B_1, B_2, \dots, B_N)$. 

Consider the sum of all elements in the sequence $B$:
$$\sum_{i=1}^{N} B_i = \sum_{i=1}^{N} (i + A_i) = \sum_{i=1}^{N} i + \sum_{i=1}^{N} A_i$$
Since $A$ is a permutation of $\{1, \dots, N\}$, $\sum A_i = \sum i = \frac{N(N+1)}{2}$.
Therefore, $\sum B_i = N(N+1)$. The average value of $B_i$ is $\frac{N(N+1)}{N} = N+1$.

If we choose $A_i = N - i + 1$, then:
$$B_i = i + (N - i + 1) = N + 1$$
In this construction, every element in the sequence $B$ becomes $N+1$. The LCM of a set where all elements are equal to $K$ is simply $K$. Thus, $\text{LCM}(N+1, N+1, \dots, N+1) = N+1$.

Since the average of the elements is $N+1$, at least one element must be $\ge N+1$. Therefore, the LCM must be at least $N+1$. Our construction achieves this theoretical lower bound, making it optimal.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from $N$ down to $1$ to print the permutation.
- **Space Complexity**: $O(1)$, as we do not store the permutation and print the values directly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a permutation A of {1, 2, ..., N} such that 
 * LCM(1+A_1, 2+A_2, ..., N+A_N) is minimized.
 * 
 * By setting A_i = N - i + 1, every term (i + A_i) becomes (N + 1).
 * The LCM of a sequence of identical values (N+1) is simply (N+1).
 * This is the minimum possible LCM because the average of the terms is (N+1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Output the permutation [N, N-1, ..., 1]
        for (int i = n; i >= 1; --i) {
            cout << i << (i == 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
```