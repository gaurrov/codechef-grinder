#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has 5 weekdays. For each day i, he has A_i hours of work to do at the office.
 * 1 hour of office work = P hours of work at home.
 * Total work in home-hours = (A_1 + A_2 + A_3 + A_4 + A_5) * P.
 * 
 * Chef has 5 weekdays, and each day has 24 hours.
 * Total available hours in a week (weekdays only) = 5 * 24 = 120 hours.
 * 
 * If the total work required (in home-hours) exceeds 120, Chef must work on the weekend.
 * Otherwise, he can complete his work within the 5 weekdays.
 * 
 * Constraints:
 * A_i <= 24, P <= 24.
 * Max total work = (24 * 5) * 24 = 120 * 24 = 2880.
 * This fits comfortably within a standard 32-bit integer, but we use long long for safety.
 */

void solve() {
    long long A[5];
    long long P;
    
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    cin >> P;
    
    long long total_work_hours = 0;
    for (int i = 0; i < 5; ++i) {
        total_work_hours += (A[i] * P);
    }
    
    // Total available hours in 5 days
    const long long total_available_hours = 5 * 24;
    
    if (total_work_hours > total_available_hours) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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