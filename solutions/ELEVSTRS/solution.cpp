#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    - Distance = N * sqrt(2)
 *    - Velocity = V1
 *    - Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    - The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    - Total distance = 2 * N
 *    - Velocity = V2
 *    - Time_elevator = (2 * N) / V2
 * 
 * To compare Time_stairs and Time_elevator without floating point issues:
 * Time_stairs < Time_elevator
 * (N * sqrt(2)) / V1 < (2 * N) / V2
 * sqrt(2) / V1 < 2 / V2
 * sqrt(2) * V2 < 2 * V1
 * Square both sides:
 * 2 * V2^2 < 4 * V1^2
 * V2^2 < 2 * V1^2
 * 
 * If V2^2 < 2 * V1^2, then Stairs are faster.
 * Otherwise, Elevator is faster (or equal).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, v1, v2;
        cin >> n >> v1 >> v2;

        // Using the derived inequality:
        // Stairs are faster if (N * sqrt(2)) / V1 < (2 * N) / V2
        // Which simplifies to sqrt(2) / V1 < 2 / V2
        // Or: sqrt(2) * V2 < 2 * V1
        // Squaring both sides: 2 * V2^2 < 4 * V1^2
        // Dividing by 2: V2^2 < 2 * V1^2
        
        long long lhs = v2 * v2;
        long long rhs = 2 * v1 * v1;

        if (lhs < rhs) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}