#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * The game proceeds by dividing both TS and JS by 2 as long as both are even.
 * This is equivalent to removing the common power of 2 from both.
 * 
 * Let JS = 2^p * n, where n is odd.
 * The game ends when:
 * 1. Both are odd: TS/2^k and JS/2^p are both odd. Since TS/2^k is always odd,
 *    this happens if JS/2^p is odd (which is always true by definition).
 *    So, if we reach a state where both are odd, it's a tie.
 * 2. TS is even, JS is odd: Tom wins.
 * 3. TS is odd, JS is even: Jerry wins.
 * 
 * After dividing both by 2^min(k, p), one of them becomes odd.
 * If TS becomes odd (i.e., k <= p), then TS is odd. If JS is also odd, it's a tie.
 * If JS becomes odd (i.e., p < k), then JS is odd and TS is even, Tom wins.
 * 
 * Wait, let's re-evaluate:
 * The game ends when the numbers are no longer both even.
 * Let TS = 2^k * m (m odd).
 * Jerry wins if, after dividing both by 2^min(k, p), TS is odd and JS is even.
 * This happens if the power of 2 in JS is strictly greater than the power of 2 in TS.
 * Let JS = 2^p * n. We need p > k.
 * Also, we are given 1 <= JS <= TS.
 * 
 * So we need to count how many JS in [1, TS] satisfy:
 * JS = 2^p * n, where p > k and n is any odd integer such that 2^p * n <= TS.
 * 
 * Since p > k, let p = k + 1, k + 2, ...
 * For a fixed p, JS = 2^p * n <= TS  =>  n <= TS / 2^p.
 * Since n must be odd, the number of odd integers n in [1, X] is (X + 1) / 2.
 * 
 * Total count = sum_{p=k+1}^{max_p} ((floor(TS / 2^p) + 1) / 2)
 * Actually, there is a simpler way:
 * JS must be a multiple of 2^(k+1).
 * Let JS = 2^(k+1) * x.
 * Then 2^(k+1) * x <= TS
 * x <= TS / 2^(k+1)
 * The number of such x is floor(TS / 2^(k+1)).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long ts;
        cin >> ts;

        // Find the power of 2 that divides ts
        long long temp_ts = ts;
        long long power_of_2 = 1;
        while (temp_ts % 2 == 0) {
            power_of_2 *= 2;
            temp_ts /= 2;
        }

        // Jerry wins if JS is a multiple of (power_of_2 * 2)
        // and JS <= TS.
        // The values are: 1*(power_of_2*2), 2*(power_of_2*2), ..., m*(power_of_2*2)
        // such that m*(power_of_2*2) <= TS
        // m <= TS / (power_of_2 * 2)
        
        long long divisor = power_of_2 * 2;
        cout << ts / divisor << "\n";
    }

    return 0;
}