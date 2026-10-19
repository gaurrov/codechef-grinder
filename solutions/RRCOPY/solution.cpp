#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * replicate it anywhere in the array. This means if we have a set of unique 
 * elements present in the final array A, we can always start with an initial 
 * array containing exactly those unique elements in any order. 
 * 
 * For example, if A = [1, 2, 3, 1, 2], the unique elements are {1, 2, 3}.
 * We can start with [1, 2, 3] and copy the subsequence [1, 2] to the end 
 * to get [1, 2, 3, 1, 2].
 * 
 * Since we want the minimal size of the initial array, and we must be able to 
 * form every element present in A, the smallest possible initial array 
 * must contain each unique element of A at least once. Thus, the minimal 
 * size is simply the count of distinct elements in A.
 * 
 * Time Complexity: O(N log N) or O(N) depending on the set implementation.
 * Space Complexity: O(N) to store the unique elements.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a set to store unique elements
    // Given constraints: Ai <= 10^5, N <= 10^5
    // A set or a boolean array/frequency array can be used.
    // Since Ai is up to 10^5, a boolean array is very efficient.
    
    vector<bool> seen(100001, false);
    int distinct_count = 0;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (!seen[val]) {
            seen[val] = true;
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}