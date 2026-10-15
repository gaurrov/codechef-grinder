#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We have two strings A and B of length N.
 * We can shuffle both. We need A[i] != B[i] for all i.
 * This means at every index i, if A[i] is 'a', B[i] must be 'b',
 * and if A[i] is 'b', B[i] must be 'a'.
 * 
 * Let countA_a be the number of 'a's in A.
 * Let countA_b be the number of 'b's in A.
 * Let countB_a be the number of 'a's in B.
 * Let countB_b be the number of 'b's in B.
 * 
 * For the condition to hold, every 'a' in A must be paired with a 'b' in B,
 * and every 'b' in A must be paired with an 'a' in B.
 * Therefore, countA_a must equal countB_b, and countA_b must equal countB_a.
 */

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int countA_a = 0, countA_b = 0;
    int countB_a = 0, countB_b = 0;

    for (char c : a) {
        if (c == 'a') countA_a++;
        else countA_b++;
    }
    for (char c : b) {
        if (c == 'a') countB_a++;
        else countB_b++;
    }

    if (countA_a == countB_b && countA_b == countB_a) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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