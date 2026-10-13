# [Dice Number (DICENUM)](https://www.codechef.com/problems/DICENUM)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each roll a standard 6-sided die three times. They want to form the largest possible 3-digit number using their three respective rolls as digits. Your task is to determine who forms the larger number, or if they result in a tie.

## Intuition & Mathematical Observation
To form the largest possible number from a set of digits, the digits must be arranged in **descending order**. 

For example, if the rolls are $\{3, 5, 2\}$, the possible permutations are $235, 253, 325, 352, 523, 532$. The largest is clearly $532$, which is achieved by placing the largest digit in the hundreds place, the second largest in the tens place, and the smallest in the units place.

**Algorithm:**
1. Collect the three rolls for Alice and store them in a list.
2. Sort Alice's list in descending order and construct the number: `digit1 * 100 + digit2 * 10 + digit3`.
3. Repeat the same process for Bob.
4. Compare the two resulting integers and print "Alice", "Bob", or "Tie" accordingly.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are always sorting a fixed array of 3 elements, the sorting operation takes constant time ($3 \log 3$).
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the three digits for each player.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the maximum number from three digits, we should sort the digits 
 * in descending order. For example, if Alice rolls 3, 2, 5, the digits 
 * sorted descending are 5, 3, 2, forming the number 532.
 * 
 * We compare the resulting numbers for Alice and Bob.
 * Since the numbers are always 3-digit integers (111 to 666), 
 * standard integer comparison is sufficient.
 */

void solve() {
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    // Store Alice's rolls in a vector and sort descending
    vector<int> alice = {a1, a2, a3};
    sort(alice.rbegin(), alice.rend());
    int alice_score = alice[0] * 100 + alice[1] * 10 + alice[2];

    // Store Bob's rolls in a vector and sort descending
    vector<int> bob = {b1, b2, b3};
    sort(bob.rbegin(), bob.rend());
    int bob_score = bob[0] * 100 + bob[1] * 10 + bob[2];

    // Compare scores
    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
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