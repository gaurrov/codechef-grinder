#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a right-angled triangle scenario where:
 * B is the base (distance between the two legs on the ground).
 * LS is the length of the left side (hypotenuse of one triangle or a side).
 * RS is the length of the right side.
 * 
 * The ladder forms a triangle with sides LS, RS, and base B.
 * Let H be the height of the ladder where the two sides meet.
 * 
 * Case 1: Minimum RS
 * This occurs when the triangle is formed such that LS is the hypotenuse 
 * and H is the other leg. By Pythagorean theorem:
 * H^2 + B^2 = LS^2  => H = sqrt(LS^2 - B^2)
 * Now, RS is the hypotenuse of the other triangle with legs H and B:
 * RS^2 = H^2 + B^2 (Wait, this is not correct).
 * 
 * Let's re-evaluate:
 * The ladder forms a triangle with sides LS, RS, and base B.
 * Let the height of the apex be H.
 * The base B is split into two segments x and y such that x + y = B.
 * LS^2 = H^2 + x^2
 * RS^2 = H^2 + y^2
 * 
 * Minimum RS: Occurs when LS is vertical (x=0). 
 * Then H = LS. The triangle is formed by H and B as legs, RS as hypotenuse.
 * RS^2 = H^2 + B^2 = LS^2 + B^2. (Wait, this is the maximum).
 * 
 * Let's look at the geometry:
 * 1. Minimum RS: The triangle is formed such that the height H is minimized.
 *    This happens when the LS is the hypotenuse and B is one leg.
 *    H^2 = LS^2 - B^2. Then RS^2 = H^2 + 0^2 (if RS is vertical).
 *    So min RS = sqrt(LS^2 - B^2).
 * 2. Maximum RS: The triangle is formed such that the height H is maximized.
 *    This happens when the LS is vertical (H = LS).
 *    Then RS^2 = H^2 + B^2 = LS^2 + B^2.
 *    So max RS = sqrt(LS^2 + B^2).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double b, ls;
        cin >> b >> ls;

        // Minimum RS: sqrt(LS^2 - B^2)
        // Maximum RS: sqrt(LS^2 + B^2)
        double min_rs = sqrt(max(0.0, ls * ls - b * b));
        double max_rs = sqrt(ls * ls + b * b);

        cout << fixed << setprecision(6) << min_rs << " " << max_rs << "\n";
    }

    return 0;
}