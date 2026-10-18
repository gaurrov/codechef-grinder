#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x = min(A, B), y = min(B, C), z = min(C, A).
 * Without loss of generality, assume A <= B <= C.
 * Then:
 * min(A, B) = A
 * min(B, C) = B
 * min(C, A) = A
 * So, A = x, B = y, A = z.
 * This implies x = z.
 * 
 * More generally, if we have three values x, y, z representing min(A, B), min(B, C), min(C, A):
 * If we sort them such that x <= y <= z:
 * The two smallest values must be equal.
 * Why?
 * Let the sorted values of {A, B, C} be a <= b <= c.
 * Then the minimums are:
 * min(A, B), min(B, C), min(C, A)
 * These will be {a, b, a} in some order.
 * So the set of values {min(A, B), min(B, C), min(C, A)} must be {a, a, b} where a <= b.
 * This means the two smallest values in the input must be equal.
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    
    // After sorting, the two smallest values (arr[0] and arr[1]) must be equal.
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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