# [Legs on a Farm (FARMLEGS)](https://www.codechef.com/problems/FARMLEGS)

- **Difficulty Rating**: 709
- **Solved in**: 2 attempt(s)

## Problem Summary
Given the total number of legs $N$ on a farm, where cows have 4 legs and chickens have 2 legs, find the **minimum** number of animals required to account for exactly $N$ legs.

## Intuition & Mathematical Observation
To minimize the total number of animals ($C + H$), we should prioritize animals with more legs (cows) because they cover the leg count faster with fewer individuals.

1.  **Mathematical Formulation**:
    *   We have the constraint: $4C + 2H = N$.
    *   We want to minimize $C + H$.
    *   From the constraint, $2C + H = N/2$.
    *   Substituting $H = N/2 - 2C$ into the total animals equation:
        *   Total = $C + (N/2 - 2C) = N/2 - C$.
    *   To minimize the total, we must **maximize $C$**.

2.  **Greedy Approach**:
    *   The maximum number of cows is $\lfloor N / 4 \rfloor$.
    *   After placing as many cows as possible, the remaining legs ($N \pmod 4$) must be covered by chickens. Since chickens have 2 legs, the remaining legs will always be either 0 or 2, which perfectly fits 0 or 1 chicken.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses basic arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * To minimize the total number of animals, we maximize the number of cows 
 * (4 legs) used to satisfy the total leg count N.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Maximize cows to minimize total animal count
    int cows = n / 4;
    
    // Use chickens (2 legs) to cover the remainder
    int remaining_legs = n % 4;
    int chickens = remaining_legs / 2;
    
    cout << (cows + chickens) << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
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