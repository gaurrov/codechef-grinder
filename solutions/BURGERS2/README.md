# [Hungry Chef (BURGERS2)](https://www.codechef.com/problems/BURGERS2)

- **Difficulty Rating**: 1187
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy exactly $N$ burgers. There are two types: normal burgers costing $X$ and premium burgers costing $Y$ (where $Y > X$). Chef has a total budget of $R$. We need to find the number of normal burgers ($n_{normal}$) and premium burgers ($n_{premium}$) such that:
1. $n_{normal} + n_{premium} = N$
2. $X \cdot n_{normal} + Y \cdot n_{premium} \le R$
3. $n_{normal}, n_{premium} \ge 0$

If it is impossible to buy $N$ burgers within the budget, output -1.

## Intuition & Mathematical Observation
To solve this, we substitute $n_{normal} = N - n_{premium}$ into the budget inequality:
$$X(N - n_{premium}) + Y \cdot n_{premium} \le R$$
$$X \cdot N - X \cdot n_{premium} + Y \cdot n_{premium} \le R$$
$$n_{premium}(Y - X) \le R - X \cdot N$$

Since $Y > X$, the term $(Y - X)$ is positive. We can isolate $n_{premium}$:
$$n_{premium} \le \frac{R - X \cdot N}{Y - X}$$

**Key Logic:**
1. **Feasibility Check**: If $R < X \cdot N$, even buying the cheapest burgers (normal) exceeds the budget. In this case, output -1.
2. **Maximizing Premium**: Since we want to find any valid combination, we calculate the maximum possible $n_{premium}$ using the derived formula.
3. **Constraints**: $n_{premium}$ cannot exceed $N$. If the calculated value is greater than $N$, we cap it at $N$.
4. **Result**: Once $n_{premium}$ is determined, $n_{normal} = N - n_{premium}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n_normal be the number of normal burgers and n_premium be the number of premium burgers.
 * We have two equations:
 * 1) n_normal + n_premium = N
 * 2) X * n_normal + Y * n_premium <= R
 * 
 * Substituting n_normal = N - n_premium into (2):
 * X * (N - n_premium) + Y * n_premium <= R
 * X * N - X * n_premium + Y * n_premium <= R
 * n_premium * (Y - X) <= R - X * N
 * 
 * Since Y > X, (Y - X) is positive.
 * n_premium <= (R - X * N) / (Y - X)
 */

void solve() {
    long long X, Y, N, R;
    cin >> X >> Y >> N >> R;

    // Minimum cost to buy N burgers is N * X (all normal)
    // If budget is less than this, it's impossible.
    if (R < N * X) {
        cout << -1 << "\n";
        return;
    }

    // Maximum possible premium burgers
    // n_premium * (Y - X) <= R - X * N
    long long max_premium = (R - N * X) / (Y - X);
    
    // We can't have more than N burgers total
    if (max_premium > N) {
        max_premium = N;
    }

    long long n_premium = max_premium;
    long long n_normal = N - n_premium;

    cout << n_normal << " " << n_premium << "\n";
}

int main() {
    // Fast I/O
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