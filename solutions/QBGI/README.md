# [Bar Queue (QBGI)](https://www.codechef.com/problems/QBGI)

- **Difficulty Rating**: 821
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many people can enter a bar before the security gate closes. We are given a string $S$ representing the sequence of people (where 'B' represents a boy and 'G' represents a girl). The gate closes as soon as the total number of boys inside exceeds twice the number of girls ($B > 2 \times G$). We need to output the total number of people who successfully entered the bar, including the person who triggered the closure.

## Intuition & Mathematical Observation
The problem can be solved using a simple linear scan (simulation). Since we need to find the exact moment the condition $B > 2 \times G$ is met, we can maintain two counters:
1. `boys`: Tracks the number of boys encountered so far.
2. `girls`: Tracks the number of girls encountered so far.

We iterate through the string character by character. For every character:
- Increment the respective counter.
- Increment an `allowed` counter to track the total number of people.
- Check the condition `boys > 2 * girls`. If it evaluates to `true`, the gate closes immediately, and we stop processing the string.

The `allowed` counter at the moment of termination gives the correct answer.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string $S$. We iterate through the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the input character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through the string S and maintain the count of boys (B) and girls (G).
 * The condition for closing the gate is: boys > 2 * girls.
 * We process the string character by character. If the condition is met, we stop.
 * The number of people allowed is the count of characters processed until the condition is met.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int boys = 0;
    int girls = 0;
    int allowed = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            boys++;
        } else {
            girls++;
        }
        
        allowed++;
        
        // Check if the condition is met
        if (boys > 2 * girls) {
            break;
        }
    }

    cout << allowed << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```