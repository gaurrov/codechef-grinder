# [Lost Weekends (LOSTWKND)](https://www.codechef.com/problems/LOSTWKND)

- **Difficulty Rating**: 1063
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a workload of $A_i$ hours for each of the 5 weekdays. Each hour of work at the office is equivalent to $P$ hours of work at home. Chef has a total of 24 hours available each day. We need to determine if the total work required exceeds the total capacity of the 5 weekdays (120 hours). If the total work required is greater than 120 hours, Chef will have to work on the weekend; otherwise, he will not.

## Intuition & Mathematical Observation
1. **Calculate Total Workload**: For each day $i$, the work required is $A_i \times P$. Summing this over the 5 weekdays gives the total work in "home-hours":
   $$\text{Total Work} = \sum_{i=1}^{5} (A_i \times P)$$
2. **Calculate Capacity**: Since there are 5 weekdays and each day has 24 hours, the total capacity is:
   $$\text{Capacity} = 5 \times 24 = 120 \text{ hours}$$
3. **Decision Logic**: 
   - If $\text{Total Work} > 120$, output `Yes`.
   - Otherwise, output `No`.

This approach is straightforward and avoids complex simulations, as we only care about the aggregate sum of hours.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we always process exactly 5 days, the loop runs a constant number of times.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the running sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of work at home.
 * Total work in home-hours = (A_1 + A_2 + A_3 + A_4 + A_5) * P.
 * 
 * Chef has 5 weekdays, and each day has 24 hours.
 * Total available hours in a week (weekdays only) = 5 * 24 = 120 hours.
 * 
 * If the total work required (in home-hours) exceeds 120, Chef must work on the weekend.
 * Otherwise, he can complete his work within the 5 weekdays.
 */

void solve() {
    long long A[5];
    long long P;
    
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    cin >> P;
    
    long long total_work_hours = 0;
    for (int i = 0; i < 5; ++i) {
        total_work_hours += (A[i] * P);
    }
    
    // Total available hours in 5 days
    const long long total_available_hours = 5 * 24;
    
    if (total_work_hours > total_available_hours) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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