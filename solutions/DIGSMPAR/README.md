# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the smallest integer $X > N$ such that the parity of the sum of digits of $X$ is different from the parity of the sum of digits of $N$.

## Intuition & Mathematical Observation
The parity of the sum of digits changes frequently as we increment a number. For example, if $N$ ends in a digit other than 9, incrementing $N$ to $N+1$ increases the digit sum by exactly 1, which flips the parity. If $N$ ends in 9, the digit sum changes more drastically, but the parity will still flip within a very small number of increments (at most 2 or 3 steps).

Because the parity flips almost immediately, a simple linear search starting from $N+1$ is highly efficient and well within the time limits for $N \le 10^9$.

## Complexity Analysis
- **Time Complexity**: $O(K \cdot \log_{10}(N))$, where $K$ is the number of increments needed to find $X$. Since $K$ is a very small constant (typically 1 or 2), the complexity is effectively $O(\log N)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current number and its digit sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest X > N such that parity(digitSum(N)) != parity(digitSum(X)).
 * Since N < 10^9, the digit sum is at most 9 * 9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * In fact, for any N, checking N+1, N+2, ... will find the required X very quickly.
 * Even in the worst case, the gap between N and X is very small. 
 * A simple linear search is optimal.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    while (true) {
        if (getDigitSum(x) % 2 != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
}

int main() {
    // Fast I/O setup
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