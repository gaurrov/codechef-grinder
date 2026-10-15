# [New-Pro Coder (SPC2025)](https://www.codechef.com/problems/SPC2025)

- **Difficulty Rating**: 467
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to classify a coder based on their performance. Given $N$ (the total number of lines of code) and $M$ (the number of lines with errors), we must determine if the coder is a "NEWBIE" or a "PRO". The condition for being a "NEWBIE" is if the number of lines with errors ($M$) is at least half of the total lines ($N$). Otherwise, the coder is a "PRO".

## Intuition & Mathematical Observation
The problem states that a coder is a "NEWBIE" if:
$$M \ge \frac{N}{2}$$

To avoid potential precision issues associated with floating-point division, we can multiply both sides of the inequality by 2:
$$2 \times M \ge N$$

This transformation allows us to perform the comparison using only integer arithmetic, which is safer and more efficient.
- If $2 \times M \ge N$, the coder has errors in at least 50% of their code, classifying them as a **NEWBIE**.
- Otherwise, they are classified as a **PRO**.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic comparison that executes in constant time regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the variables $N$ and $M$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * M >= N / 2  <=>  2 * M >= N
 * 
 * Constraints:
 * 1 <= N, M <= 1000
 * The values fit comfortably within standard integer types.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    // Read total lines (N) and error lines (M)
    if (!(cin >> n >> m)) return 0;

    // Logic: If errors are present in at least half of the total lines (N/2),
    // he is a NEWBIE. Otherwise, he is a PRO.
    // Using 2 * M >= N handles the "at least half" condition correctly.
    
    if (2 * m >= n) {
        cout << "NEWBIE" << "\n";
    } else {
        cout << "PRO" << "\n";
    }

    return 0;
}
```