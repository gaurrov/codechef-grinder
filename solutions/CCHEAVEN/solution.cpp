#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef lives for L years. We are given a string S of length L where S[i] is '1' (good) or '0' (bad).
 * Chef goes to heaven if there exists some L' (1 <= L' <= L) such that the number of good years
 * in the first L' years is at least 50% of L'.
 * 
 * Let 'good' be the count of '1's in the prefix of length i.
 * The condition is: good / i >= 0.5
 * This is equivalent to: 2 * good >= i
 * 
 * We iterate through the string, maintaining a running count of good years.
 * At each year i (1-indexed), we check if 2 * good >= i.
 * If this condition is met for any i, Chef goes to heaven.
 * 
 * Time Complexity: O(L) per test case, O(sum of L) total.
 * Space Complexity: O(L) to store the string.
 */

void solve() {
    int L;
    cin >> L;
    string S;
    cin >> S;

    int good_years = 0;
    bool can_go_to_heaven = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current year is i + 1
        // Condition: good_years / (i + 1) >= 0.5
        // Which is: 2 * good_years >= i + 1
        if (2 * good_years >= (i + 1)) {
            can_go_to_heaven = true;
            break;
        }
    }

    if (can_go_to_heaven) {
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