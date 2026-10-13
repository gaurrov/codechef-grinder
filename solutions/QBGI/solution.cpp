#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to iterate through the string S and maintain the count of boys (B) and girls (G).
 * Let 'b' be the number of boys and 'g' be the number of girls currently inside.
 * The condition for closing the gate is: b > 2 * g.
 * We process the string character by character. If the condition is met, we stop.
 * The number of people allowed is the count of characters processed until the condition is met.
 * Note: The problem states "as soon as the number of boys... exceeds twice the number of girls, 
 * the security closes the entrance." This implies the person who caused the condition 
 * to be met is still counted as having entered before the gate closes.
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