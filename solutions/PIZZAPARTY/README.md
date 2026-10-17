# [Pizza Party (PIZZAPARTY)](https://www.codechef.com/problems/PIZZAPARTY)

- **Difficulty Rating**: 238
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is hosting a party with $A$ friends (all boys) and $B$ girls. Chef himself is also a boy. Each boy consumes 4 slices of pizza, and each girl consumes 3 slices. Given that each pizza contains 8 slices, calculate the minimum number of whole pizzas required to satisfy everyone's hunger.

## Intuition & Mathematical Observation
1. **Total People**: Since Chef is a boy, the total number of boys is $A + 1$. The number of girls is $B$.
2. **Total Slices Needed**: 
   - Slices for boys: $(A + 1) \times 4$
   - Slices for girls: $B \times 3$
   - Total Slices = $(A + 1) \times 4 + B \times 3$
3. **Calculating Pizzas**: Since each pizza has 8 slices, we need to divide the total slices by 8. Because we cannot order a fraction of a pizza, we must round up to the nearest whole number (ceiling division).
4. **Ceiling Division Trick**: In integer arithmetic, $\lceil \frac{x}{y} \rceil$ can be calculated as `(x + y - 1) / y`. Here, $y = 8$, so the formula becomes `(total_slices + 7) / 8`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ because the solution involves a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - Chef is a boy, so total boys = A + 1.
 * - Total girls = B.
 * - Each boy eats 4 slices, each girl eats 3 slices.
 * - Total slices needed = (A + 1) * 4 + B * 3.
 * - Each pizza has 8 slices.
 * - Number of pizzas needed = ceil(Total slices / 8).
 * - Using integer arithmetic, ceil(x / y) = (x + y - 1) / y.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B directly as per the problem statement
    if (cin >> A >> B) {
        long long total_boys = A + 1;
        long long total_girls = B;
        
        long long total_slices = (total_boys * 4) + (total_girls * 3);
        
        // Calculate ceiling division: (total_slices + 7) / 8
        long long pizzas_needed = (total_slices + 7) / 8;
        
        cout << pizzas_needed << endl;
    }

    return 0;
}
```