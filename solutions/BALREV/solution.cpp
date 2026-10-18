#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to reverse any substring that has an equal number of 0s and 1s.
 * If we have a substring with equal 0s and 1s, we can effectively swap 0s and 1s 
 * within that range to sort them. 
 * 
 * More generally, if we have any number of 0s and 1s in the string, we can 
 * eventually move all 0s to the front and all 1s to the back. 
 * Why? Because if we have at least one '0' and one '1' in the string, we can 
 * always find a substring containing them and manipulate the string. 
 * Specifically, any binary string can be transformed into a sorted version 
 * (all 0s followed by all 1s) using the given operation because we can 
 * repeatedly pick substrings to move 0s to the left.
 * 
 * Thus, the lexicographically smallest string is simply the string with all 
 * the 0s counted and placed at the beginning, followed by all the 1s.
 */

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    int count0 = 0;
    int count1 = 0;

    for (char c : a) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // The lexicographically smallest string is all 0s followed by all 1s.
    string result = "";
    for (int i = 0; i < count0; ++i) {
        result += '0';
    }
    for (int i = 0; i < count1; ++i) {
        result += '1';
    }

    cout << result << "\n";
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