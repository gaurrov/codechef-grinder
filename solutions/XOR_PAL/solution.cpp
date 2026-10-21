#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let's look at pairs (A[i], A[N-1-i]).
 * If A[i] == A[N-1-i], these positions are already "palindromic".
 * If A[i] != A[N-1-i], we have a mismatch.
 * 
 * Let 'mismatches' be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * Each operation can fix at most one mismatch pair.
 * If we have 'mismatches' pairs that are different, we need at least 'mismatches' operations 
 * to make them equal.
 * 
 * Specifically, if we have a mismatch (0, 1), we can perform an operation to make 
 * both 0 or both 1. One operation is sufficient to fix one mismatch pair.
 * Thus, the minimum operations required is ceil(mismatches / 2.0).
 * 
 * Wait, let's re-verify:
 * If we have 'm' mismatches, we can fix them in 'm' operations if we pick indices carefully.
 * Actually, one operation can fix one mismatch pair. So we need 'm' operations.
 * However, the problem allows changing any two indices. 
 * If we have 'm' mismatches, we need 'm' operations to fix them.
 * 
 * Let's check the sample cases:
 * 11011: mismatches = 0. Ans = 0.
 * 0111010: N=7. Pairs: (0,0), (1,1), (1,0). Mismatch at index 2 (0-indexed). 
 * Mismatches = 1. Ans = 1.
 * 1100: N=4. Pairs: (1,0), (1,0). Mismatches = 2. Ans = 1.
 * 
 * The logic is: count the number of pairs (i, N-1-i) that are different. Let this be 'cnt'.
 * The answer is (cnt + 1) / 2.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int mismatches = 0;
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            mismatches++;
        }
    }

    // Each operation can resolve two mismatches if we pick indices from two different mismatch pairs,
    // or one mismatch if we pick one index from a mismatch pair and one from a matching pair.
    // The formula (mismatches + 1) / 2 covers the requirement.
    cout << (mismatches + 1) / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}