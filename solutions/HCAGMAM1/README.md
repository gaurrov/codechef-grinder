# [Chef And Salary Pay (HCAGMAM1)](https://www.codechef.com/problems/HCAGMAM1)

- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a binary string $S$ of length 30, where '1' represents a working day and '0' represents a leave. The salary is calculated based on two components:
1. The total number of working days multiplied by $X$.
2. The length of the longest consecutive streak of working days multiplied by $Y$.

The goal is to calculate the total salary for each test case.

## Intuition & Mathematical Observation
The problem requires two distinct pieces of information from the string:
1. **Total Count**: A simple linear scan to count the total number of '1's in the string.
2. **Longest Streak**: A linear scan to track the current consecutive count of '1's. Whenever we encounter a '0', we compare the `current_streak` with the `max_streak` found so far and reset `current_streak` to zero. 

**Key Edge Case**: It is important to perform a final check after the loop finishes. If the string ends with a '1', the `max_streak` might not have been updated for the final sequence.

The formula for the salary is:
$$\text{Salary} = (\text{Total '1's} \times X) + (\text{Max Streak of '1's} \times Y)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. Since $N=30$ is constant, this is effectively $O(1)$ per test case, leading to a total complexity of $O(T)$.
- **Space Complexity**: $O(N)$ to store the input string, which is $O(1)$ given the fixed constraint.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We are given a binary string of length 30.
 * - '1' represents a working day, '0' represents a leave.
 * - Salary = (Total number of '1's * X) + (Length of longest streak of '1's * Y).
 * - Constraints: T <= 10^4, X, Y <= 999, |S| = 30.
 * - Time complexity per test case: O(|S|), which is O(1) since |S| is fixed at 30.
 * - Total time complexity: O(T).
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    string s;
    cin >> s;

    long long total_working_days = 0;
    long long max_streak = 0;
    long long current_streak = 0;

    for (char c : s) {
        if (c == '1') {
            total_working_days++;
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    // Final check for streak ending at the last character
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }

    long long salary = (total_working_days * X) + (max_streak * Y);
    cout << salary << "\n";
}

int main() {
    // Fast I/O
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