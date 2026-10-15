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