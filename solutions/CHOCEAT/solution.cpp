#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A milk chocolates and B dark chocolates.
 * Total chocolates = A + B.
 * Satisfaction increases if (milk_eaten != dark_eaten).
 * 
 * Let m be the number of milk chocolates eaten and d be the number of dark chocolates eaten.
 * At any step, the condition is m != d.
 * 
 * To maximize satisfaction, we want to avoid the state where m == d as much as possible.
 * The only time m == d is possible is when we have eaten an equal number of both.
 * Since we must eat all A + B chocolates, we will inevitably pass through states where m == d.
 * Specifically, every time we reach a point where m == d, we do not get satisfaction for that step.
 * 
 * Let's analyze the sequence:
 * If we have A milk and B dark, we can eat all of the larger quantity first.
 * Suppose A > B. We eat all A milk chocolates, then all B dark chocolates.
 * The number of milk chocolates eaten will be 1, 2, ..., A.
 * The number of dark chocolates eaten will be 0 until we start eating dark ones.
 * 
 * Actually, the optimal strategy is to eat all of the more abundant chocolate type first,
 * then eat the other type.
 * If A > B:
 * Eat all A milk chocolates: 
 * Step 1: m=1, d=0 (m!=d, sat++)
 * Step 2: m=2, d=0 (m!=d, sat++)
 * ...
 * Step A: m=A, d=0 (m!=d, sat++)
 * Then eat all B dark chocolates:
 * Step A+1: m=A, d=1 (m!=d, sat++)
 * ...
 * Step A+B: m=A, d=B (m!=d, sat++)
 * Total satisfaction = A + B.
 * 
 * Wait, is it always A+B? Let's check sample 2: A=1, B=1.
 * Step 1: Eat milk. m=1, d=0. Sat++.
 * Step 2: Eat dark. m=1, d=1. No sat.
 * Total = 1. (A+B-1 = 1).
 * 
 * Sample 1: A=1, B=2.
 * Eat dark, dark, milk.
 * 1: m=0, d=1 (sat)
 * 2: m=0, d=2 (sat)
 * 3: m=1, d=2 (sat)
 * Total = 3. (A+B = 3).
 * 
 * The pattern is: if A == B, satisfaction is A+B-1.
 * If A != B, satisfaction is A+B.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        if (a == b) {
            cout << (a + b - 1) << "\n";
        } else {
            cout << (a + b) << "\n";
        }
    }
    return 0;
}