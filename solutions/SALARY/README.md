# [The Minimum Number Of Moves (SALARY)](https://www.codechef.com/problems/SALARY)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ workers, each with an initial salary $W_i$. In one operation, we can choose one worker and increase the salary of all *other* $N-1$ workers by 1. The goal is to find the minimum number of operations required to make all workers' salaries equal.

## Intuition & Mathematical Observation
The key observation is to look at the relative differences between salaries. 

1. **Relative Change**: Increasing everyone's salary except for worker $i$ by 1 is mathematically equivalent to decreasing worker $i$'s salary by 1 relative to the rest of the group.
2. **Target State**: To make all salaries equal using only increments, the final salary of every worker must be at least the initial maximum salary. However, we don't need to reach a specific target value; we only need to reach a state where all values are equal.
3. **The Minimum Salary**: If we consider the minimum salary in the array ($min\_w$), every other worker $i$ has a "surplus" of $(W_i - min\_w)$. To make everyone equal to the minimum salary (relative to each other), we must perform exactly $(W_i - min\_w)$ operations on each worker $i$.
4. **Formula**: The total number of operations required is the sum of the differences between each salary and the minimum salary:
   $$\text{Total Operations} = \sum_{i=1}^{N} (W_i - min\_w)$$

This approach works because each operation effectively reduces the gap between the current salary and the minimum salary until all salaries converge.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of workers. We iterate through the array twice: once to find the minimum and once to calculate the sum of differences.
- **Space Complexity**: $O(N)$ to store the salaries. This can be optimized to $O(1)$ if we calculate the sum and minimum on the fly while reading the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation of increasing everyone's salary except one worker is equivalent 
 * to reducing the chosen worker's salary relative to the others.
 * To make all salaries equal, we must reduce every worker's salary to the 
 * level of the minimum salary currently present in the group.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    long long min_w = 20000; // Constraint: W_i <= 10000
    
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        if (w[i] < min_w) {
            min_w = w[i];
        }
    }

    // The total number of operations is the sum of differences 
    // between each salary and the minimum salary.
    long long operations = 0;
    for (int i = 0; i < n; ++i) {
        operations += (w[i] - min_w);
    }

    cout << operations << "\n";
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