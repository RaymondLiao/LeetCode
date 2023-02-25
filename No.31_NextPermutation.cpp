// Author:  Sheng (Raymond) Liao
// Date:    February 2023

/* 31. Next Permutation

   A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

 * For example, for arr = [1,2,3], the following are all the permutations of arr: 
   [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

   The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
   More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
   then the next permutation of that array is the permutation that follows it in the sorted container. 
   If such arrangement is not possible, the array must be rearranged as the lowest possible order 
   (i.e., sorted in ascending order).

 * For example, the next permutation of arr = [1,2,3] is [1,3,2].
 * Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 * While the next permutation of arr = [3,2,1] is [1,2,3] 
   because [3,2,1] does not have a lexicographical larger rearrangement.

   Given an array of integers nums, find the next permutation of nums.

   The replacement must be in place and use only constant extra memory.
*/

class Solution {
public:
    inline void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void nextPermutation(vector<int>& nums) {
        bool descending = false, ndescending = true;
        int size = nums.size(), px = 0, py = 0;

        // Step 1. Find number X in the input array following the pattern:
        // [X <, >=, >=... >=] OR [X < the last one].
        for (int i = 0; i < size - 1; ++i) {
            descending = (nums[i] >= nums[i+1]);

            if (descending) {
                ndescending = false;
            }
            else {
                px = i;
            }
        }
        // Special case: never descending
        if (ndescending) {
            if (1 == size) {
                return;
            }

            swap(nums[size - 2], nums[size - 1]);
            return;
        }

        // Step 2. Find Y in numbers following X which is the smallest one greater than X.
        py = px;
        for (int i = px + 1; i < size; ++i) {
            if (nums[i] > nums[px] && ((px == py) || nums[i] < nums[py])) {
                py = i;
            }
        }

        // Step 3. Swap X and Y, then sort the numbers following Y in the ascending order.
        // The result array is the next permutation of the input.
        swap(nums[px], nums[py]);
        for (int i = py; i < size - 1; ++i) {
            if (nums[i] < nums[i+1]) {
                swap(nums[i], nums[i+1]);
            }
            else {
                break;
            }
        }
        
        int count = 0, start = (px != py) ? px + 1 : px;
        //cout << "px: " << px << "\npy: " << py << "\nstart: " << start << "\nceil((start + size-1) * 0.5): " << ceil((start + size-1) * 0.5) << endl;
        for (int i = start; i < ceil((start + size-1) * 0.5); ++i) {
            swap(nums[i], nums[size- 1 - count++]);
        }

        return;
    }
};