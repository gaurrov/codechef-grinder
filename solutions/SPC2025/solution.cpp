#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved is a NEWBIE if M >= N / 2.0.
 * To avoid floating point arithmetic, we can multiply both sides by 2:
 * M >= N / 2  <=>  2 * M >= N
 * 
 * Constraints:
 * 1 <= N, M <= 1000
 * The values fit comfortably within standard integer types.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies a single test case structure, 
    // but standard competitive programming practice handles potential 
    // multiple test cases if the input format specifies it.
    // Given the problem description format, we read N and M.
    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Logic: If errors are present in at least half of the total lines (N/2),
    // he is a NEWBIE. Otherwise, he is a PRO.
    // Using 2 * M >= N handles the "at least half" condition correctly for both
    // even and odd N.
    // Example N=10, M=6: 2*6 = 12 >= 10 (True -> NEWBIE)
    // Example N=9, M=4: 2*4 = 8 >= 9 (False -> PRO)
    
    if (2 * m >= n) {
        cout << "NEWBIE" << "\n";
    } else {
        cout << "PRO" << "\n";
    }

    return 0;
}