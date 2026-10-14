#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1: Convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as a 
 *    potential lowercase letter 'x'.
 * 2. Operation 2: Choose one lowercase letter and convert all its occurrences 
 *    to another lowercase letter. This can be done exactly once.
 * 
 * Strategy:
 * - First, convert all uppercase letters to their lowercase counterparts.
 *   This is always optimal because it increases the count of some lowercase 
 *   letter without any penalty.
 * - After this, we have a string consisting only of lowercase letters.
 * - Let the frequency of each character 'a'-'z' be count[c].
 * - We want to maximize the count of some character 'target' after merging 
 *   one character 'source' into 'target'.
 * - If we choose to merge 'source' into 'target' (where source != target), 
 *   the new count of 'target' becomes count[target] + count[source].
 * - If we don't merge (or merge a character that doesn't exist), the count 
 *   remains count[target].
 * - We iterate over all possible pairs of (source, target) and find the maximum.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> counts(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else {
            counts[c - 'a']++;
        }
    }

    int max_score = 0;

    // Case 1: No merge or merging a character that doesn't exist
    for (int i = 0; i < 26; ++i) {
        max_score = max(max_score, counts[i]);
    }

    // Case 2: Merge one character 'source' into 'target'
    for (int target = 0; target < 26; ++target) {
        for (int source = 0; source < 26; ++source) {
            if (target == source) continue;
            max_score = max(max_score, counts[target] + counts[source]);
        }
    }

    cout << max_score << "\n";
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