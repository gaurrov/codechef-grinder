# [Survival Time (FIZZBUZZ23_2)](https://www.codechef.com/problems/FIZZBUZZ23_2)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
A family of 5 members consumes $X$ buns each per day, totaling $5 \times X$ buns daily. They currently have $N$ buns in stock and are guaranteed to receive an additional supply of buns after $D$ days. We need to calculate the total number of days the family can survive, considering both their current stock and the additional supply that arrives after $D$ days.

## Intuition & Mathematical Observation
1. **Daily Consumption**: Since there are 5 family members and each eats $X$ buns, the total daily consumption is $5 \times X$.
2. **Days from Current Stock**: The number of full days the current $N$ buns can sustain the family is given by the integer division: $\lfloor N / (5 \times X) \rfloor$.
3. **Total Survival Time**: The family survives for the duration provided by their current stock, plus the $D$ days they are guaranteed to survive once the new supply arrives. Thus, the formula is:
   $$\text{Total Days} = \lfloor N / (5 \times X) \rfloor + D$$
4. **Constraints**: Given $N < 500$, $X \le 10$, and $D < 20$, the values fit comfortably within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily consumption = 5 * X.
 * The number of days the buns last is floor(N / (5 * X)).
 * Total survival time = (days buns last) + D.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long N, X, D;
        cin >> N >> X >> D;

        long long daily_consumption = 5 * X;
        
        // Calculate how many full days the buns can feed the family
        long long days_with_food = N / daily_consumption;
        
        // Total survival time is the days with food plus the extra D days
        long long total_days = days_with_food + D;
        
        cout << total_days << "\n";
    }

    return 0;
}
```