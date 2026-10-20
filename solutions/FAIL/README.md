# [Failing Grades (FAIL)](https://www.codechef.com/problems/FAIL)

- **Difficulty Rating**: 697
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes $N$ tests. We are given the marks obtained in each test sequentially. We need to determine if the average of the marks remains at least 40 after every single test from the 1st to the $N$-th. If the average is $\ge 40$ for all $i \in [1, N]$, output "Yes"; otherwise, output "No".

## Intuition & Mathematical Observation
The average after $i$ tests is defined as:
$$\text{Average}_i = \frac{\sum_{j=1}^{i} \text{marks}_j}{i}$$

The problem requires $\text{Average}_i \ge 40$ for all $i$. To avoid floating-point precision issues, we can rewrite the inequality:
$$\frac{\sum_{j=1}^{i} \text{marks}_j}{i} \ge 40 \implies \sum_{j=1}^{i} \text{marks}_j \ge 40 \times i$$

By maintaining a running sum of the marks as we iterate through the input, we can check this condition in constant time for each test. If at any point the running sum is less than $40 \times i$, the condition is violated, and we can conclude the answer is "No".

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of tests. We iterate through the input array exactly once.
- **Space Complexity**: $O(1)$, as we only store the running sum and the current test mark, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef takes N tests. We need to check if the average after every test i (1 to N)
 * is at least 40.
 * Average after i tests = (Sum of marks from 1 to i) / i.
 * Condition: (Sum of marks from 1 to i) / i >= 40
 * Which is equivalent to: (Sum of marks from 1 to i) >= 40 * i.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= 100.
 * The sum will not exceed 100 * 100 = 10,000, which fits in a standard int.
 */

void solve() {
    int N;
    cin >> N;
    
    long long current_sum = 0;
    bool possible = true;
    
    for (int i = 1; i <= N; ++i) {
        int marks;
        cin >> marks;
        current_sum += marks;
        
        // Check if average is >= 40
        // Average = current_sum / i
        // Condition: current_sum / i >= 40  => current_sum >= 40 * i
        if (current_sum < 40LL * i) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```