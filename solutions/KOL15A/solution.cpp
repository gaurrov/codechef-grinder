#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Processing a string (KOL15A)
 * Approach: Iterate through each character of the string. If the character is a digit
 * (checked via isdigit()), convert it to its integer value and add it to the running sum.
 * Time Complexity: O(T * |S|), where |S| is the length of the string.
 * Space Complexity: O(|S|) to store the string.
 */

void solve() {
    string s;
    cin >> s;
    
    long long sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            // Convert char digit to int by subtracting '0'
            sum += (c - '0');
        }
    }
    cout << sum << "\n";
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