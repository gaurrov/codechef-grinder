#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A consists only of 0s and 1s.
 * The operation is to pick adjacent elements A[i], A[i+1], add |A[i] - A[i+1]| to the score,
 * and remove them.
 * 
 * Note that |A[i] - A[i+1]| is 1 if the pair is (0, 1) or (1, 0), and 0 if the pair is (0, 0) or (1, 1).
 * We want to maximize the number of (0, 1) or (1, 0) pairs we can form.
 * 
 * Let c0 be the total count of 0s and c1 be the total count of 1s in the array.
 * Each operation removes one 0 and one 1 (if we pick a pair with difference 1)
 * or two 0s or two 1s (if we pick a pair with difference 0).
 * 
 * Since we want to maximize the score, we want to pair as many 0s with 1s as possible.
 * Each such pair contributes 1 to the score.
 * If we have c0 zeros and c1 ones, we can form at most min(c0, c1) pairs of (0, 1).
 * 
 * Is it always possible to achieve min(c0, c1)?
 * Yes. Because we can always pick adjacent elements, we can effectively treat this as 
 * matching 0s and 1s. Since the total length is N, and we perform N/2 operations,
 * we are essentially partitioning the array into N/2 pairs.
 * The number of pairs with different values is limited by the count of the minority element.
 * Specifically, if we have c0 zeros and c1 ones, the maximum number of pairs with 
 * different values is min(c0, c1).
 */

void solve() {
    int N;
    cin >> N;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 0) {
            c0++;
        } else {
            c1++;
        }
    }
    
    // The maximum score is simply the number of pairs of (0, 1) we can form.
    // Each pair (0, 1) or (1, 0) adds 1 to the score.
    // We can form min(c0, c1) such pairs.
    cout << min(c0, c1) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}