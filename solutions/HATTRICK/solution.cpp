#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HATTRICK
 * A hattrick occurs if there are three consecutive 'W's in the sequence of 6 balls.
 * We read the 6 inputs as strings to handle both digits and 'W'.
 * We check all possible windows of size 3:
 * (0,1,2), (1,2,3), (2,3,4), (3,4,5)
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check for 3 consecutive wickets
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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