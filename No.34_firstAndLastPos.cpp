// Author:  Sheng (Raymond) Liao
// Date:    February 2023

/* 34. Find First and Last Position of Element in Sorted Array 
   
   Given an array of integers nums sorted in non-decreasing order, 
   find the starting and ending position of a given target value.

   If target is not found in the array, return [-1, -1].

   You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Bisection Search
        vector<int> res = {-1, -1};

        if (nums.size() == 0) {
            return res;
        }

        int size = nums.size(), last = size - 1;
        int l = 0, r = last;
        int p = (l + r)* 0.5;

        while (l < r) {
            if (nums[p] == target) {
                res[0] = res[1] = p;

                int i = p - 1;
                while (i >= 0 && nums[i] == target) {
                    --i;
                }
                res[0] = i + 1;


                i = p + 1;
                while (i < size && nums[i] == target) {
                    ++i;
                }
                res[1] = i - 1;

                return res;
            }
            else if (nums[p] > target) {
                r = p - 1;
            }
            else {
                l = p + 1;
            }

            p = (l + r) * 0.5;
        }

        // Here, p must be equal to l and r may be equal or less than l.
        if (nums[p] == target) {
            res[0] = res[1] = p;
        }

        return res;
    }
};