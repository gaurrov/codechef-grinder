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