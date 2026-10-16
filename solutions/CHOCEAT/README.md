# [Chocolate Eating (CHOCEAT)](https://www.codechef.com/problems/CHOCEAT)

- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $A$ milk chocolates and $B$ dark chocolates. He eats all $A + B$ chocolates one by one. A "satisfaction" point is earned at each step if the number of milk chocolates eaten so far is not equal to the number of dark chocolates eaten so far. The goal is to determine the maximum total satisfaction Chef can achieve by choosing the order in which he eats the chocolates.

## Intuition & Mathematical Observation
Let $m$ be the number of milk chocolates eaten and $d$ be the number of dark chocolates eaten at any given time. We want to maximize the number of steps where $m \neq d$.

1.  **Case $A \neq B$**: If the quantities are unequal, we can eat all of the more abundant chocolate type first. For example, if $A > B$, we eat all $A$ milk chocolates one by one. During these $A$ steps, $m$ increases from $1$ to $A$ while $d$ remains $0$. Since $m \neq d$ is always true, we gain $A$ satisfaction points. Then, we eat all $B$ dark chocolates. During these $B$ steps, $m$ remains $A$ while $d$ increases from $1$ to $B$. Since $A > B$, $m$ will never equal $d$ during this phase either. Thus, we gain $A + B$ satisfaction points.
2.  **Case $A = B$**: If the quantities are equal, we will inevitably reach a state where $m = d$ at the very last step (when $m = A$ and $d = B = A$). At this final step, the condition $m \neq d$ is violated, resulting in no satisfaction point. For all previous $A + B - 1$ steps, we can arrange the eating order such that $m \neq d$. Therefore, the total satisfaction is $(A + B) - 1$.

**Conclusion**: 
- If $A = B$, the answer is $A + B - 1$.
- If $A \neq B$, the answer is $A + B$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a simple comparison and arithmetic operation. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize steps where (milk_eaten != dark_eaten).
 * If A != B, we can always eat all of one type then all of the other,
 * ensuring m != d at every step, resulting in A + B satisfaction.
 * If A == B, the final step will always result in m == d, 
 * so the total satisfaction is (A + B) - 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        if (a == b) {
            // If equal, we lose one point at the very end
            cout << (a + b - 1) << "\n";
        } else {
            // If unequal, we can avoid m == d entirely
            cout << (a + b) << "\n";
        }
    }
    return 0;
}
```