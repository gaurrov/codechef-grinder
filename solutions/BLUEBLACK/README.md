# [Blue and Black Pens (BLUEBLACK)](https://www.codechef.com/problems/BLUEBLACK)

- **Difficulty Rating**: -1
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine the minimum cost to acquire 3 blue pens. We are given two pricing options:
1. Buying 3 individual blue pens, each costing $A$.
2. Buying a set containing 1 blue pen and 1 black pen, costing $B$ (where we only care about the blue pen included).

Essentially, we need to compare the cost of buying 3 blue pens individually versus buying 3 sets (each containing 1 blue pen and 1 black pen) to satisfy the requirement of having 3 blue pens.

## Intuition & Mathematical Observation
To obtain 3 blue pens, we have two primary strategies:

1. **Individual Purchase**: Buy 3 blue pens at price $A$ each.
   - Total Cost = $3 \times A$
2. **Set Purchase**: Buy 3 sets, where each set contains 1 blue pen and 1 black pen at price $B$ each.
   - Total Cost = $3 \times B$

*Correction based on problem logic:* The problem implies we need to reach a total of 3 blue pens. If we buy the sets, we need 3 sets to get 3 blue pens. Thus, we compare $3 \times A$ and $3 \times B$. 

*Note:* If the problem allows mixing or specific constraints, we evaluate the cheapest way to reach the count of 3. Given the simplicity, we calculate the minimum of the two total costs.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the calculated costs.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B;
    // Read the cost of a blue pen (A) and the cost of a set (B)
    if (!(std::cin >> A >> B)) return 0;

    // Option 1: Buy 3 blue pens individually
    int cost1 = 3 * A;
    
    // Option 2: Buy 3 sets (each containing 1 blue pen)
    int cost2 = 3 * B;

    // Output the minimum of the two options
    std::cout << std::min(cost1, cost2) << std::endl;

    return 0;
}
```