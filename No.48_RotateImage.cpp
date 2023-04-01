// Author:  Sheng (Raymond) Liao
// Date:    April 2023

/* 48. Rotate Image

   You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

   You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
   DO NOT allocate another 2D matrix and do the rotation.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dim = matrix.size();    // n
        int odd = dim % 2;          // n = 2k + 1 ?
        int halfDim = dim * 0.5f;   // k

        for (int round = 0; round < halfDim; ++round) {
            int times = odd ? (1 + 2 * round) : 2 * round;

            for (int circle = 0; circle < times + 1; ++circle) {
                rotateFour(matrix[halfDim - 1 - round][halfDim - 1 - round + circle],
                           matrix[halfDim - 1 - round + circle][halfDim + odd + round],
                           matrix[halfDim + odd + round][halfDim + odd + round - circle],
                           matrix[halfDim + odd + round - circle][halfDim - 1 - round]);
            }
        }
    }

private:
    inline void rotateFour(int& p1, int& p2, int& p3, int& p4) {
        int temp = p1;
        p1 = p4;
        p4 = p3;
        p3 = p2;
        p2 = temp;
    }
};