# [Coloured Balloons (BALLOONS)](https://www.codechef.com/problems/BALLOONS)

- **Difficulty Rating**: 584
- **Solved in**: 3 attempt(s)

## Problem Summary
We are given $N$ different types of balloons, indexed from $1$ to $N$. For each type $i$, we are given the quantity $A_i$ of balloons purchased. The cost of a single balloon of type $i$ is equal to its index $i$. We need to calculate the total cost incurred for all the balloons purchased.

## Intuition & Mathematical Observation
The problem asks for the sum of the costs of all balloons. Since there are $A_i$ balloons of type $i$, and each costs $i$ rupees, the total cost for type $i$ is simply $A_i \times i$.

To find the total cost for all $N$ types, we sum these values:
$$\text{Total Cost} = \sum_{i=1}^{N} (A_i \times i)$$

Given the constraints ($N \le 100$ and $A_i \le 100$), the maximum possible cost is $100 \times \sum_{i=1}^{100} i \approx 100 \times 5050 = 505,000$. This value comfortably fits within a standard 32-bit integer, though using `long long` is a safe practice to prevent overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of balloon types. We iterate through the input array exactly once. With $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the running total and the current balloon count, without needing to store the entire array in memory.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * The total cost is the sum of (A_i * i) for i from 1 to N.
 * Constraints: T <= 100, N <= 100, A_i <= 100.
 * Max possible cost = 100 * (100 * 100) = 1,000,000, which fits in a standard int.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        int A_i;
        cin >> A_i;
        // The i-th colour balloon costs i rupees.
        // We bought A_i balloons of this colour.
        total_cost += (long long)A_i * i;
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```