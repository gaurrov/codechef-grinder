#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily consumption = 5 * X.
 * If N < 5 * X, the family cannot eat for even one day.
 * Otherwise, the number of days the buns last is floor(N / (5 * X)).
 * Total survival time = (days buns last) + D.
 * 
 * Constraints:
 * N < 500, X <= 10, D < 20.
 * The values are small enough that standard integer types are sufficient,
 * but long long is used for safety.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long N, X, D;
        cin >> N >> X >> D;

        long long daily_consumption = 5 * X;
        
        // Calculate how many full days the buns can feed the family
        long long days_with_food = N / daily_consumption;
        
        // Total survival time is the days with food plus the extra D days
        long long total_days = days_with_food + D;
        
        cout << total_days << "\n";
    }

    return 0;
}