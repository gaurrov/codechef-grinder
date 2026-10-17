# [Weapon Value (SC31)](https://www.codechef.com/problems/SC31)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given $N$ contestants, each possessing a set of 10 types of weapons, represented as a binary string of length 10. When two contestants battle, they perform an XOR operation on their weapon strings. If both have a weapon of a certain type, it is destroyed (1 XOR 1 = 0). If only one has it, they keep it (1 XOR 0 = 1). We need to determine how many weapons remain after all $N$ contestants have battled each other.

## Intuition & Mathematical Observation
The key observation is that the XOR operation is both **associative** and **commutative**. This means the order in which the battles occur does not change the final result. 

Mathematically, if we have $N$ strings $S_1, S_2, \dots, S_N$, the final state of the weapons is simply:
$$Result = S_1 \oplus S_2 \oplus \dots \oplus S_N$$
Since the length of the string is fixed at 10, we can treat each string as a 10-bit integer. We XOR all input integers together, and the final answer is the number of set bits (population count) in the resulting integer.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times L)$, where $T$ is the number of test cases, $N$ is the number of contestants, and $L$ is the length of the string (10). Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(L)$ (or $O(1)$ effectively), as we only store the current XOR sum and the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The battle mechanism describes an XOR operation.
 * Since the XOR operation is associative and commutative, the final set of 
 * weapons the winner has is simply the XOR sum of all initial weapon strings.
 */

void solve() {
    int N;
    cin >> N;
    
    // We can represent the 10-bit string as an integer since 2^10 = 1024.
    int final_xor = 0;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        // Convert binary string to integer
        int current_val = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == '1') {
                current_val |= (1 << (9 - j));
            }
        }
        
        // XOR the current contestant's weapons into the total
        final_xor ^= current_val;
    }
    
    // Count the number of set bits (1s) in the final XOR result
    int weapon_count = 0;
    for (int j = 0; j < 10; ++j) {
        if ((final_xor >> j) & 1) {
            weapon_count++;
        }
    }
    
    cout << weapon_count << "\n";
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