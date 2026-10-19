#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem: PLACE0110
 * We have X strings of "01" and Y strings of "10".
 * Each string has 1 internal transition.
 * Concatenating two strings creates an extra transition if the boundary characters differ.
 * "01" ends in 1, "10" ends in 0.
 * "01" starts with 0, "10" starts with 1.
 * Alternating 01 and 10 (01100110...) results in 0 boundary transitions.
 * If we have excess of one type, we must place them adjacently, creating 1 transition per excess.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;
    
    if (X == 0 || Y == 0) {
        cout << X + Y - 1 << endl;
    } else {
        int diff = abs(X - Y);
        if (diff == 0) {
            cout << X + Y << endl;
        } else {
            cout << X + Y + diff - 1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}