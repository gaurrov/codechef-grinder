#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has 52 cards. She has K people in total (including herself).
 * She needs to distribute the cards equally among K people.
 * Let X be the number of cards each person receives.
 * Then K * X <= 52.
 * To minimize the number of discarded cards, we need to maximize the number of cards used.
 * The number of cards used will be the largest multiple of K that is less than or equal to 52.
 * Let this be M = (52 / K) * K.
 * The number of discarded cards is 52 - M.
 * Since 52 % K gives the remainder when 52 is divided by K,
 * the remainder is exactly the number of cards that cannot be distributed equally.
 * Therefore, the answer is simply 52 % K.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int k;
        cin >> k;
        
        // The number of cards to discard is the remainder of 52 divided by K.
        // If 52 is perfectly divisible by K, the remainder is 0, which is correct.
        int result = 52 % k;
        
        cout << result << "\n";
    }

    return 0;
}