// File:    4Sum.cpp
// Author:  Sheng (Raymond) Liao
// Date:    February 2023

class Solution {
public:
    inline vector<int> formQuad(int num1, int num2, int num3, int num4, unordered_map<int, int>& numCounts) {
        unordered_map<int, int> numCountsDup = numCounts;
        // Check if adding the same number whose count is not enough.
        --numCountsDup[num1];
        if (--numCountsDup[num2] < 0 || --numCountsDup[num3] < 0 || --numCountsDup[num4] < 0) {
            return {};
        }
        
        //cout << "quat: [" << num1 << ", " << num2 << ", " << num3 << ", " << num4 << "]" << endl;
        return {num1, num2, num3, num4};
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> quads;

        unordered_map<int, int> numCounts;
        unordered_map<int, set<pair<int, int>>> twoSumPairs;
        vector<int> twoSums;

        // O(n^2)
        for (int i = 0; i < nums.size(); ++i) {
            numCounts[nums[i]]++;

            for (int j = i + 1; j < nums.size(); ++j) {
                int small = (nums[i] <= nums[j]) ? nums[i] : nums[j];
                int large = (small == nums[i]) ? nums[j] : nums[i];
                int twoSum = small + large;
 
                twoSumPairs[twoSum].insert({small, large});
            }
        }
        for (auto iter = twoSumPairs.begin(); iter != twoSumPairs.end(); ++iter) {
            twoSums.push_back(iter->first);
        }

        // DEBUGGING LOG ---------------------------------------------------------------------
        // cout << "[numCounts]" << endl;
        // for (auto iter = numCounts.begin(); iter != numCounts.end(); ++iter) {
        //     cout << iter->first << ": " << iter->second << endl;
        // }
        // cout << "[twoSums]" << endl;
        // for (auto iter1 = twoSumPairs.begin(); iter1 != twoSumPairs.end(); ++iter1) {
        //     cout << iter1->first << ": " << "[";
        //     for (auto iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
        //         cout << "(" << iter2->first << "," << iter2->second << "), ";
        //     }
        //     cout << "]" << endl;
        // }
        // --------------------------------------------------------------------- DEBUGGING LOG

        for (auto vecIter1 = twoSums.begin(); vecIter1 != twoSums.end();) {
            // Overflow Test
            if (INT_MAX - abs(*vecIter1) < abs(target)) {
                ++vecIter1;
                continue;
            }

            int another = target - *vecIter1;
            auto vecIter2 = find(twoSums.begin(), twoSums.end(), another);
            if (twoSums.end() != vecIter2) {
                // Two 2Sums are different.
                if (vecIter1 != vecIter2) {
                    // O(n^2)
                    for (auto setIter1 = twoSumPairs[*vecIter1].begin(); setIter1 != twoSumPairs[*vecIter1].end(); ++setIter1) {
                        for (auto setIter2 = twoSumPairs[*vecIter2].begin(); setIter2 != twoSumPairs[*vecIter2].end(); ++setIter2) {
                            int num1 = setIter1->first, num2 = setIter1->second, num3 = setIter2->first, num4 = setIter2->second;                            
                            vector<int> quad = formQuad(num1, num2, num3, num4, numCounts);
                            if (0 == quad.size()) {
                                continue;
                            }
                            sort(quad.begin(), quad.end());
                            quads.insert(quad);
                        }
                    }

                    twoSums.erase(vecIter2);
                }
                // Otherwise
                else {
                    vector<pair<int, int>> pairs;
                    for (auto iter = twoSumPairs[*vecIter1].begin(); iter != twoSumPairs[*vecIter1].end(); ++iter) {
                        pairs.push_back({iter->first, iter->second});
                    }
                    // O(n^2)
                    for (int i = 0; i < pairs.size(); ++i) {
                        for (int j = i; j < pairs.size(); ++j) {
                            int num1 = pairs[i].first, num2 = pairs[i].second, num3 = pairs[j].first, num4 = pairs[j].second;
                            vector<int> quad = formQuad(num1, num2, num3, num4, numCounts);
                            if (0 == quad.size()) {
                                continue;
                            }
                            sort(quad.begin(), quad.end());
                            quads.insert(quad);
                        }
                    }
                }

                //cout << "2Sum A: " << *vecIter1 << ", B: " << *vecIter2 << endl;
                vecIter1 = twoSums.erase(vecIter1);
            }
            else{
                ++vecIter1;
            }
        }

        for (auto iter = quads.begin(); iter != quads.end(); ++iter) {
            res.push_back(*iter);
        }
        return res;
    }
};