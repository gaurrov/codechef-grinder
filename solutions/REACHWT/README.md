# [Reach Weight (REACHWT)](https://www.codechef.com/problems/REACHWT)

- **Difficulty Rating**: 530
- **Solved in**: 3 attempt(s)

## Problem Summary
The goal is to reach a target weight $N$ using a combination of 1kg weights (costing 20 units each) and 2kg weights (costing 30 units each) such that the total cost is minimized.

## Intuition & Mathematical Observation
To minimize the total cost, we need to analyze the cost-efficiency of each weight type:
- **1kg weight**: Costs 20 per kg.
- **2kg weight**: Costs 30 per 2kg, which is 15 per kg.

Since the 2kg weight is more cost-efficient (15/kg vs 20/kg), we should prioritize using as many 2kg weights as possible.

1. **If $N$ is even**: We can reach the target weight entirely using 2kg weights. The number of 2kg weights required is $N/2$.
   - Total Cost = $(N/2) \times 30$.
2. **If $N$ is odd**: We must use at least one 1kg weight to make the remaining weight even. After using one 1kg weight, the remaining weight is $(N-1)$, which can be covered by $(N-1)/2$ weights of 2kg.
   - Total Cost = $20 + ((N-1)/2) \times 30$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - 1kg weight costs 20.
 * - 2kg weight costs 30.
 * - Cost per kg for 1kg weight = 20.
 * - Cost per kg for 2kg weight = 15.
 * 
 * Strategy:
 * To minimize cost, maximize the number of 2kg weights used.
 * - If N is even: Use (N/2) weights of 2kg. Total cost = (N/2) * 30.
 * - If N is odd: Use one 1kg weight and (N-1)/2 weights of 2kg. 
 *   Total cost = 20 + ((N-1)/2) * 30.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        if (!(cin >> n)) break;

        if (n % 2 == 0) {
            // Even N: Use only 2kg weights
            cout << (n / 2) * 30 << "\n";
        } else {
            // Odd N: Use one 1kg weight, remainder is even
            cout << 20 + ((n - 1) / 2) * 30 << "\n";
        }
    }

    return 0;
}
```