# [Christmas Trees (XMASTREE)](https://www.codechef.com/problems/XMASTREE)

- **Difficulty Rating**: 300
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef purchases $N$ Christmas trees at a cost of $A$ rupees per tree. Later, he sells $M$ of those trees at a price of $B$ rupees per tree. The goal is to calculate the total profit (or loss) Chef makes from these transactions.

## Intuition & Mathematical Observation
The problem asks for the net financial result of buying and selling. 
1. **Total Cost**: Chef buys $N$ trees at $A$ rupees each, resulting in a total expenditure of $N \times A$.
2. **Total Revenue**: Chef sells $M$ trees at $B$ rupees each, resulting in a total income of $M \times B$.
3. **Profit Calculation**: Profit is defined as the difference between total revenue and total cost.
   $$\text{Profit} = (\text{Total Revenue}) - (\text{Total Cost})$$
   $$\text{Profit} = (M \times B) - (N \times A)$$

Since the inputs can be large enough to potentially exceed the range of a standard 32-bit integer, we use `long long` in C++ to ensure no overflow occurs during multiplication.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the four input variables and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef bought N trees for A rupees each, and sold M trees for B rupees each.
 * Formula: Profit = (M * B) - (N * A)
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, A, M, B;
    
    // Read the four inputs: N, A, M, B
    if (cin >> N >> A >> M >> B) {
        // Calculate profit using long long to prevent overflow
        long long profit = (M * B) - (N * A);
        
        // Output the result
        cout << profit << "\n";
    }

    return 0;
}
```