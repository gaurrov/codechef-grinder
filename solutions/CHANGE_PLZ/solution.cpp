#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * You pay 100 dollars. The fare is X.
 * The change owed to you is (100 - X).
 * The driver can only pay back in multiples of 10.
 * We need the maximum multiple of 10 that is less than or equal to (100 - X).
 * 
 * Let R = 100 - X.
 * We need to find the largest multiple of 10 <= R.
 * This is equivalent to floor(R / 10) * 10.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change owed
        int change_owed = 100 - x;
        
        // The driver pays back in 10 dollar bills.
        // The number of 10 dollar bills is floor(change_owed / 10).
        // The total amount returned is (change_owed / 10) * 10.
        int result = (change_owed / 10) * 10;
        
        cout << result << "\n";
    }
    
    return 0;
}