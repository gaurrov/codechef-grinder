# [The Tom and Jerry Game! (EOEO)](https://www.codechef.com/problems/EOEO)

- **Difficulty Rating**: 1337
- **Solved in**: 1 attempt(s)

## Problem Summary
Tom and Jerry are playing a game with a number $TS$. Jerry chooses a number $JS$ such that $1 \le JS \le TS$. The game proceeds as follows:
1. If both $TS$ and $JS$ are even, both are divided by 2. This repeats until at least one of them is odd.
2. If $TS$ becomes odd and $JS$ is even, Jerry wins.
3. If $TS$ is even and $JS$ is odd, Tom wins.
4. If both are odd, it is a tie.

We need to find the number of possible values for $JS$ such that Jerry wins.

## Intuition & Mathematical Observation
Let $TS = 2^k \cdot m$, where $m$ is an odd integer. 
The game continues dividing both numbers by 2 until one becomes odd. This is equivalent to removing the common power of 2 from both numbers. 

For Jerry to win, the final state must result in $TS$ being odd and $JS$ being even.
- After dividing $TS$ by $2^k$, $TS$ becomes $m$ (which is odd).
- For $JS$ to remain even after this process, $JS$ must have been divisible by a higher power of 2 than $TS$.
- Specifically, if $JS = 2^p \cdot n$ (where $n$ is odd), Jerry wins if $p > k$.

Thus, we are looking for the number of integers $JS \in [1, TS]$ such that $JS$ is a multiple of $2^{k+1}$.
If we let $JS = x \cdot 2^{k+1}$, then:
$$x \cdot 2^{k+1} \le TS$$
$$x \le \frac{TS}{2^{k+1}}$$

The number of such positive integers $x$ is simply $\lfloor \frac{TS}{2^{k+1}} \rfloor$.

## Complexity Analysis
- **Time Complexity**: $O(\log(TS))$ per test case, due to the loop required to find the highest power of 2 that divides $TS$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Jerry wins if, after dividing both TS and JS by their greatest common power of 2,
 * TS becomes odd and JS remains even.
 * 
 * Let TS = 2^k * m (where m is odd).
 * Jerry wins if JS is a multiple of 2^(k+1).
 * The number of such multiples JS <= TS is floor(TS / 2^(k+1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long ts;
        cin >> ts;

        // Find the highest power of 2 that divides ts
        long long temp_ts = ts;
        long long power_of_2 = 1;
        while (temp_ts % 2 == 0) {
            power_of_2 *= 2;
            temp_ts /= 2;
        }

        // Jerry wins if JS is a multiple of (power_of_2 * 2)
        // The number of such multiples <= TS is TS / (power_of_2 * 2)
        long long divisor = power_of_2 * 2;
        cout << ts / divisor << "\n";
    }

    return 0;
}
```