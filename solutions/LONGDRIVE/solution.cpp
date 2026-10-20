#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial state: 10 hours, average speed X.
 * Total distance covered = 10 * X.
 * Let 'n' be the number of additional hours.
 * Let 'v' be the average speed in these 'n' hours (max 100 km/h).
 * New average speed = (10 * X + n * v) / (10 + n) = Y.
 * 
 * We want to find the minimum integer 'n' such that:
 * 10 * X + n * v = Y * (10 + n)
 * 10 * X + n * v = 10 * Y + n * Y
 * n * (v - Y) = 10 * (Y - X)
 * 
 * Since we want to minimize 'n', we should maximize 'v'.
 * The maximum speed per hour is 100 km/h.
 * So, n * (100 - Y) >= 10 * (Y - X)
 * n >= (10 * (Y - X)) / (100 - Y)
 * 
 * Since 'n' must be an integer, we take the ceiling of the division.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // We need to find minimum n such that:
        // (10 * x + n * 100) / (10 + n) >= y
        // 10 * x + 100 * n >= 10 * y + n * y
        // n * (100 - y) >= 10 * (y - x)
        // n >= (10 * (y - x)) / (100 - y)
        
        long long numerator = 10 * (y - x);
        long long denominator = 100 - y;
        
        // Ceiling division: (a + b - 1) / b
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}