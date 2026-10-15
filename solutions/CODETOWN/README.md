# [Reach Codetown (CODETOWN)](https://www.codechef.com/problems/CODETOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 8, determine if it is possible to transform $S$ into the string "CODETOWN". The transformation rules allow replacing a consonant with any other consonant and a vowel with any other vowel. Essentially, we need to check if the vowel/consonant pattern of the input string $S$ matches the pattern of "CODETOWN" exactly.

## Intuition & Mathematical Observation
The problem defines a transformation rule based on the character type (vowel or consonant). Since a vowel can only be replaced by another vowel and a consonant by another consonant, the "type" of the character at each index $i$ is an **invariant**.

1. Let $T$ be the target string "CODETOWN".
2. For any index $i$ (where $0 \le i < 8$), the character $S[i]$ must be a vowel if $T[i]$ is a vowel, and $S[i]$ must be a consonant if $T[i]$ is a consonant.
3. If this condition holds for all 8 positions, the transformation is possible; otherwise, it is impossible.

**Vowel Definition**: The vowels are defined as {'A', 'E', 'I', 'O', 'U'}. All other uppercase English letters are considered consonants.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string (which is fixed at 8). Since we iterate through the string exactly once, the complexity is $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the target string and a few boolean flags.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The rule states we can transition from T1 to T2 if:
 * 1. A consonant is replaced by a consonant.
 * 2. A vowel is replaced by a vowel.
 * 
 * This implies that the "vowel/consonant" status of each position in the string
 * is invariant. If index 'i' in the starting string is a vowel, it must remain 
 * a vowel in any reachable string. If it is a consonant, it must remain a consonant.
 * 
 * Therefore, a string S can reach "CODETOWN" if and only if for every index i (0 to 7),
 * the type (vowel or consonant) of S[i] matches the type of "CODETOWN"[i].
 * 
 * Vowels: A, E, I, O, U
 */

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
    string s;
    cin >> s;
    string target = "CODETOWN";
    
    bool possible = true;
    for (int i = 0; i < 8; ++i) {
        // Check if the vowel/consonant status matches at each position
        if (isVowel(s[i]) != isVowel(target[i])) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```