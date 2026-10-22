# [Money Double (MONEYDOUBLE)](https://www.codechef.com/problems/MONEYDOUBLE)

- **Difficulty Rating**: 784
- **Solved in**: 2 attempt(s)

## Problem Summary
You start with an initial amount $X$. For each of the $Y$ years, you can choose one of two actions:
1. Add 1000 to your current amount ($X = X + 1000$).
2. Double your current amount ($X = X \times 2$).

The goal is to maximize the final amount after $Y$ years.

## Intuition & Mathematical Observation
Since the number of years $Y$ is very small ($Y \le 10$), the total number of possible sequences of choices is $2^Y$. Even for the maximum $Y=10$, there are only $2^{10} = 1024$ possible paths. 

We can solve this using a simple recursive approach (Depth First Search). At each year, we branch into two possibilities:
- **Branch A**: Add 1000 and proceed to the next year.
- **Branch B**: Double the amount and proceed to the next year.

By comparing the results of these two branches at every step, we can determine the maximum possible value. Because $Y$ is small, this brute-force recursion is highly efficient and well within the time limits for the given number of test cases.

## Complexity Analysis
- **Time Complexity**: $O(2^Y)$ per test case. With $Y \le 10$, this is $O(1024)$ per test case. Given $T$ test cases, the total complexity is $O(T \times 2^Y)$, which is approximately $10^5 \times 1024 \approx 10^8$ operations, fitting comfortably within the 1-second time limit.
- **Space Complexity**: $O(Y)$ due to the recursion stack depth, which is $O(10)$ or $O(1)$ in constant space terms.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have Y years and 2 choices each year. Total states = 2^Y.
 * Since Y <= 10, 2^10 = 1024.
 * For 10^5 test cases, 10^5 * 1024 is ~10^8 operations, which fits 
 * within the 1-2 second time limit.
 */

long long getMaxMoney(long long X, int Y) {
    // Base case: No more years left
    if (Y == 0) {
        return X;
    }
    
    // Option 1: Add 1000
    long long res1 = getMaxMoney(X + 1000, Y - 1);
    
    // Option 2: Double
    long long res2 = getMaxMoney(X * 2, Y - 1);
    
    // Return the best outcome from the two choices
    return max(res1, res2);
}

void solve() {
    long long X;
    int Y;
    cin >> X >> Y;
    
    // Since Y is very small, we can use a simple recursive search.
    cout << getMaxMoney(X, Y) << "\n";
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