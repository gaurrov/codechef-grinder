#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to minimize (C + H) subject to 4*C + 2*H = N.
 * Total animals = C + H.
 * Since 4*C + 2*H = N, we have 2*C + H = N/2.
 * H = N/2 - 2*C.
 * Total animals = C + (N/2 - 2*C) = N/2 - C.
 * To minimize (N/2 - C), we must maximize C.
 * The maximum number of cows is floor(N / 4).
 * 
 * Example:
 * N = 2: C = 0, H = 1. Total = 1.
 * N = 4: C = 1, H = 0. Total = 1.
 * N = 6: C = 1, H = 1. Total = 2.
 * 
 * The logic:
 * cows = N / 4
 * remaining_legs = N % 4
 * chickens = remaining_legs / 2
 * result = cows + chickens
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    int cows = n / 4;
    int remaining_legs = n % 4;
    int chickens = remaining_legs / 2;
    
    cout << (cows + chickens) << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}