#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with the smaller health becomes 0, 
 * and the player with the larger health reduces by the smaller one.
 * 
 * To maximize Anna's final health, we want her to fight the opponent 
 * who has the least health remaining after they have fought each other.
 * 
 * Let's analyze the fight between Bob and Claudio first:
 * After Bob and Claudio fight, the remaining health of the winner is |B - C|.
 * Let this be R = |B - C|.
 * Then Anna fights this winner (or the one who remains).
 * Anna's final health will be A - R, provided A > R.
 * 
 * So, the condition for Anna to have positive health is A > |B - C|.
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // The optimal strategy is to have Bob and Claudio fight first.
    // The winner of that fight will have health |B - C|.
    // Then Anna fights that winner.
    // Anna's final health = A - |B - C|.
    // Anna has positive health if A - |B - C| > 0, which is A > |B - C|.
    
    long long remaining_opponent_health = abs(B - C);
    
    if (A > remaining_opponent_health) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}