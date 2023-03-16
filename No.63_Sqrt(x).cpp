// Author:  Sheng (Raymond) Liao
// Date:    March 2023

/* 63. Sqrt(x)

   Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
   The returned integer should be non-negative as well.

   You must not use any built-in exponent function or operator.

 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/

class Solution {
public:
    int mySqrt(int x) {
        // Edge case: x = 2147395599

        if (0 == x) {
            return 0;
        }

        // Binary Search
        int l = 0, r = x;
        float root = (l + r) * 0.5f;

        while (l < r) {
            // Note that we do not use root*root to avoid overflow issue.
            if (x / root > root) {
                // Round up.
                l = (int)root + 1;
            }
            else if (x / root < root){
                // Round down.
                r = (int)root;
            }
            else {
                break;
            }

            root = (l + r) * 0.5f;
        }

        if (x / (int)root < root) {
            root -= 1;
        }

        return root;
    }
};
