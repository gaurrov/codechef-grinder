#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a permutation A of {1, 2, ..., N} such that 
 * LCM(1+A_1, 2+A_2, ..., N+A_N) is minimized.
 * 
 * Let B_i = i + A_i. We want to minimize LCM(B_1, B_2, ..., B_N).
 * Since A is a permutation of {1, ..., N}, the sum of B_i is:
 * sum(B_i) = sum(i) + sum(A_i) = 2 * sum(1 to N) = 2 * (N * (N + 1) / 2) = N(N + 1).
 * 
 * To minimize the LCM, we want the values of B_i to be as small as possible 
 * or to share many common factors.
 * A simple strategy is to pair the largest values with the smallest values 
 * to keep the sums B_i relatively uniform.
 * 
 * Specifically, if we set A_i = N - i + 1, then:
 * B_i = i + (N - i + 1) = N + 1.
 * In this case, all B_i are equal to N + 1.
 * The LCM(N+1, N+1, ..., N+1) = N + 1.
 * This is the smallest possible value for the LCM because the maximum value 
 * in the set {B_1, ..., B_N} must be at least N+1 (since the average is N+1).
 * 
 * Thus, the permutation A = [N, N-1, ..., 1] yields the minimum LCM.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Output the permutation [N, N-1, ..., 1]
        for (int i = n; i >= 1; --i) {
            cout << i << (i == 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}