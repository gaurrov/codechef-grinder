# [Cab Rides (CABRIDE)](https://www.codechef.com/problems/CABRIDE)

- **Difficulty Rating**: 945
- **Solved in**: 1 attempt(s)

## Problem Summary
We need to transport $N$ people using cabs that can hold a maximum of 4 people each. The cost of a cab carrying $X$ people is defined as $\max(200, 100 \times X)$. The goal is to minimize the total cost to transport all $N$ people.

## Intuition & Mathematical Observation
To minimize the total cost, we analyze the cost per person for different cab capacities:
- **1 person**: $\max(200, 100 \times 1) = 200$ (Cost per person: 200)
- **2 people**: $\max(200, 100 \times 2) = 200$ (Cost per person: 100)
- **3 people**: $\max(200, 100 \times 3) = 300$ (Cost per person: 100)
- **4 people**: $\max(200, 100 \times 4) = 400$ (Cost per person: 100)

**Observations:**
1. The most efficient rate is **100 per person**, which is achieved when a cab carries 2, 3, or 4 people.
2. If $N=1$, we are forced to pay 200 for a single cab.
3. If $N$ is even ($N \ge 2$), we can group everyone into pairs of 2. Each pair costs 200, resulting in a total cost of $(N/2) \times 200 = 100 \times N$.
4. If $N$ is odd ($N \ge 3$), we can use one cab for 3 people (cost 300) and group the remaining $N-3$ people into pairs of 2. The total cost is $300 + ((N-3)/2) \times 200 = 300 + 100(N-3) = 100 \times N$.

Thus, for all $N > 1$, the minimum cost is simply $100 \times N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a simple arithmetic formula. Total complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A cab can hold at most 4 people.
 * Cost for X people in one cab = max(200, 100 * X).
 * 
 * Strategy:
 * - For N = 1, cost is 200.
 * - For N >= 2, we can always achieve a rate of 100 per person by 
 *   grouping people into sets of 2, 3, or 4.
 * - Therefore, the minimum cost is 100 * N for N > 1.
 */

void solve() {
    long long N;
    cin >> N;
    if (N == 1) {
        cout << 200 << "\n";
    } else {
        cout << 100 * N << "\n";
    }
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