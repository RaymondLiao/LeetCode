// Author:  Sheng (Raymond) Liao
// Date:    March 2023

/* 45. Jump Game II

   You are given a 0-indexed array of integers nums of length n.
   You are initially positioned at nums[0].

   Each element nums[i] represents the maximum length of a forward jump from index i.
   In other words, if you are at nums[i], you can jump to any nums[i + j] where:

   * 0 <= j <= nums[i] and
   * i + j < n

   Return the minimum number of jumps to reach nums[n - 1].
   The test cases are generated such that you can reach nums[n - 1].
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int stepAvailable = 0, stepBound = 0, forwardBoundMax = 0;

        for (int i = 0; i < nums.size();) {
            stepAvailable = nums[i];
            stepBound = i + stepAvailable;
            forwardBoundMax = stepBound;

            if (stepBound >= nums.size() - 1) {
                if (i != nums.size() - 1 && stepBound != i) {
                    jumps++;
                }
                break;
            }

            for (int j = i; j <= stepBound && j < nums.size(); j++) {
                if (j + nums[j] > forwardBoundMax) {
                    i = j;
                    forwardBoundMax = j + nums[j];
                }
            }

            if (forwardBoundMax != stepBound) {
                jumps++;
            }

            //cout << "i: " << i << "\tforwardBoundMax: " << forwardBoundMax << endl;
            if (i == nums.size() - 1) {
                break;
            }
            if (forwardBoundMax >= nums.size() - 1) {
                jumps++;
                break;
            }
        }

        return jumps;
    }
};
