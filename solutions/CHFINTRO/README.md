# [Chef and Interactive Contests (CHFINTRO)](https://www.codechef.com/problems/CHFINTRO)

- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is organizing a contest and wants to categorize participants based on their current ratings. Given a minimum rating threshold $r$, we need to evaluate $N$ participants. For each participant with a rating $R$, we must output "Good boi" if $R \ge r$, and "Bad boi" if $R < r$.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. For every input rating $R$, we simply compare it against the threshold $r$:
- If $R \ge r$, the condition is satisfied, and the participant is labeled as "Good boi".
- If $R < r$, the condition is not satisfied, and the participant is labeled as "Bad boi".

Since the constraints on $N$ and $R$ are within standard integer limits, a simple loop iterating through the input array is sufficient to solve the problem efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of participants. We iterate through the list of ratings exactly once, performing a constant-time comparison for each.
- **Space Complexity**: $O(1)$, as we only store a few variables ($N, r, R$) and do not require any additional data structures that scale with the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Interactive Contests
 * Logic: For each contestant with rating R, if R >= r, they are "Good boi".
 * Otherwise, they are "Bad boi".
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long r;
    
    // Read N (number of participants) and r (threshold rating)
    if (!(cin >> N >> r)) return 0;

    // Process each contestant
    for (int i = 0; i < N; ++i) {
        long long R;
        cin >> R;
        
        // Check if the contestant's rating meets the threshold
        if (R >= r) {
            cout << "Good boi" << "\n";
        } else {
            cout << "Bad boi" << "\n";
        }
    }

    return 0;
}
```