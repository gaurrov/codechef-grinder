# [Equal Card Game (EQCARDGAME)](https://www.codechef.com/problems/EQCARDGAME)

- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has a standard deck of 52 cards. She wants to distribute these cards equally among $K$ people (including herself). If the cards cannot be distributed perfectly, she must discard the remaining cards. The goal is to find the minimum number of cards that need to be discarded so that every person receives an equal number of cards.

## Intuition & Mathematical Observation
To distribute 52 cards equally among $K$ people, each person must receive $X$ cards such that $K \times X \le 52$. To minimize the number of discarded cards, we need to maximize the total number of cards distributed ($K \times X$).

Mathematically, the number of cards distributed will be the largest multiple of $K$ that is less than or equal to 52. The number of discarded cards is the difference between the total cards (52) and this multiple. This is exactly the definition of the modulo operator:
$$\text{Discarded Cards} = 52 \pmod K$$

For example:
- If $K = 5$, $52 \pmod 5 = 2$. (10 cards each, 2 discarded).
- If $K = 13$, $52 \pmod{13} = 0$. (4 cards each, 0 discarded).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the modulo operation is a constant-time arithmetic operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. She has K people in total (including herself).
 * She needs to distribute the cards equally among K people.
 * Let X be the number of cards each person receives.
 * Then K * X <= 52.
 * To minimize the number of discarded cards, we need to maximize the number of cards used.
 * The number of cards used will be the largest multiple of K that is less than or equal to 52.
 * Let this be M = (52 / K) * K.
 * The number of discarded cards is 52 - M.
 * Since 52 % K gives the remainder when 52 is divided by K,
 * the remainder is exactly the number of cards that cannot be distributed equally.
 * Therefore, the answer is simply 52 % K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int k;
        cin >> k;
        
        // The number of cards to discard is the remainder of 52 divided by K.
        // If 52 is perfectly divisible by K, the remainder is 0, which is correct.
        int result = 52 % k;
        
        cout << result << "\n";
    }

    return 0;
}
```