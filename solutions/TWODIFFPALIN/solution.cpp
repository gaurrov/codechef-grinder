#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are palindromes,
 * each containing exactly A zeros and B ones.
 * 
 * Let the total length be N = A + B.
 * 1. If both A and B are odd, it is impossible to form even one palindrome.
 *    Why? In a palindrome, if the total length is even, both counts must be even.
 *    If the total length is odd, exactly one count must be odd and the other even.
 *    If both A and B are odd, the total length A+B is even. In an even-length
 *    palindrome, every character must appear an even number of times.
 *    Thus, if A and B are both odd, we cannot form any palindrome.
 * 
 * 2. If A is odd and B is odd, output "No".
 * 
 * 3. If A=1 or B=1:
 *    If A=1, B=1, total length 2. Palindromes: "01" (no), "10" (no). Only "01" is not a palindrome.
 *    Actually, if A=1, B=1, we can't form a palindrome.
 *    If A=1, B=even, we can form "1...0...1". Only one unique palindrome exists.
 *    So if A=1 or B=1, we can only form one unique palindrome. Output "No".
 * 
 * 4. Otherwise (if A and B are not both odd, and neither is 1):
 *    We can always construct at least two different palindromes.
 *    Example: A=2, B=2 -> "0110", "1001" (Yes)
 *    Example: A=2, B=3 -> "01110", "10101" (Yes)
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // If both are odd, we cannot form a palindrome at all.
    if (A % 2 != 0 && B % 2 != 0) {
        cout << "No" << "\n";
    } 
    // If either is 1, we can only form one unique palindrome.
    // e.g., A=1, B=4 -> "11011" (only one way)
    else if (A == 1 || B == 1) {
        cout << "No" << "\n";
    } 
    // Otherwise, we can construct at least two.
    else {
        cout << "Yes" << "\n";
    }
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