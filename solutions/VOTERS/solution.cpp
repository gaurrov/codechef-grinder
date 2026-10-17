#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three sorted lists of voter IDs. We need to find IDs that appear
 * in at least two of the three lists.
 * 
 * Constraints:
 * N1, N2, N3 <= 50,000. Total IDs <= 150,000.
 * Time limit: ~1.15s.
 * 
 * Approach:
 * Since the total number of IDs is relatively small (150,000), we can use a 
 * frequency map (std::map or std::unordered_map) to count occurrences of each ID.
 * Given the constraints and the requirement for ascending order, a std::map 
 * is efficient enough (O(N log N)) and keeps keys sorted.
 * Alternatively, since we have all inputs, we can store them in a single vector,
 * sort them, and count consecutive occurrences.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    // Using a map to store the frequency of each ID.
    // Map keys are automatically sorted.
    map<int, int> counts;

    int total_elements = n1 + n2 + n3;
    for (int i = 0; i < total_elements; ++i) {
        int id;
        cin >> id;
        counts[id]++;
    }

    // Collect IDs that appear at least twice
    vector<int> result;
    for (auto const& [id, count] : counts) {
        if (count >= 2) {
            result.push_back(id);
        }
    }

    // Output the count of such IDs
    cout << result.size() << "\n";
    
    // Output the IDs in ascending order
    for (int id : result) {
        cout << id << "\n";
    }

    return 0;
}