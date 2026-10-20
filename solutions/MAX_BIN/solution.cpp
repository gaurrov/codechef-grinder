#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the decimal value of a binary string:
 * 1. The most significant bit (the leftmost bit) has the highest impact.
 * 2. If the first character is '0', changing it to '1' (Type 2 operation) is the 
 *    most effective way to increase the value.
 * 3. Adding '0's at the end (Type 1 operation) shifts all existing bits to the 
 *    left, effectively multiplying the current value by 2^k.
 * 
 * Strategy:
 * - If the first character is '0', use one Type 2 operation to change it to '1'.
 * - Use all remaining operations as Type 1 operations by appending '0's to the end.
 * - Since we want to maximize the value, we prioritize changing the first bit to '1'
 *   if it's '0', then append all remaining allowed operations as '0's at the end.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // If the first bit is '0', we should change it to '1' first.
    // This costs 1 operation.
    if (S[0] == '0') {
        S[0] = '1';
        K--;
    }

    // After ensuring the first bit is '1' (if possible), 
    // any remaining operations should be used to append '0's at the end.
    // Appending '0' at the end is equivalent to multiplying by 2,
    // which is always better than changing internal '0's to '1's 
    // because it increases the power of all existing bits.
    
    cout << S;
    for (int i = 0; i < K; ++i) {
        cout << '0';
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}