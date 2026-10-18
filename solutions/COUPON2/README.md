# [Chef and Coupon (COUPON2)](https://www.codechef.com/problems/COUPON2)

- **Difficulty Rating**: 1222
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef orders food for two days. Each day, he orders three items. There is a delivery charge $D$ for each order unless the order total is at least $150$. Chef can purchase a coupon for price $C$, which makes the delivery charge $0$ for both days. We need to determine if buying the coupon is strictly cheaper than not buying it.

## Intuition & Mathematical Observation
To decide whether to buy the coupon, we compare the total cost in two scenarios:

1.  **Without Coupon:**
    *   Chef pays for all items on Day 1 ($SumA$) and Day 2 ($SumB$).
    *   Chef pays the delivery charge $D$ for both days regardless of the order total.
    *   **Total Cost** = $SumA + SumB + 2 \times D$.

2.  **With Coupon:**
    *   Chef pays for all items on Day 1 ($SumA$) and Day 2 ($SumB$).
    *   Chef pays the coupon price $C$.
    *   The delivery charge for each day is waived **only if** that day's order total is $\ge 150$.
    *   **Total Cost** = $SumA + SumB + C + (\text{delivery}_1) + (\text{delivery}_2)$, where $\text{delivery}_i = 0$ if $Sum_i \ge 150$, else $D$.

We output `YES` if `costWith < costWithout`, otherwise `NO`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since we perform a constant number of arithmetic operations per test case, the solution is highly efficient.
- **Space Complexity**: $O(1)$, as we only use a fixed number of variables to store the sums and costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Cost without coupon: (SumA + D) + (SumB + D) = SumA + SumB + 2*D
 * - Cost with coupon: SumA + SumB + C + (delivery_charge_day1) + (delivery_charge_day2)
 *   - delivery_charge_day1 = (SumA >= 150) ? 0 : D
 *   - delivery_charge_day2 = (SumB >= 150) ? 0 : D
 * 
 * Chef buys the coupon if: Cost_with_coupon < Cost_without_coupon
 */

void solve() {
    long long D, C;
    cin >> D >> C;
    
    long long A1, A2, A3;
    cin >> A1 >> A2 >> A3;
    long long sumA = A1 + A2 + A3;
    
    long long B1, B2, B3;
    cin >> B1 >> B2 >> B3;
    long long sumB = B1 + B2 + B3;
    
    // Total cost without coupon
    long long costWithout = sumA + sumB + 2 * D;
    
    // Total cost with coupon
    long long deliveryDay1 = (sumA >= 150) ? 0 : D;
    long long deliveryDay2 = (sumB >= 150) ? 0 : D;
    long long costWith = sumA + sumB + C + deliveryDay1 + deliveryDay2;
    
    if (costWith < costWithout) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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