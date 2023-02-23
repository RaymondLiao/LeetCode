// File:    NextPermutation.cpp
// Author:  Sheng (Raymond) Liao
// Date:    February 2023

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