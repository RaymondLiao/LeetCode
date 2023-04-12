// Author:  Sheng (Raymond) Liao
// Date:    April 2023

/* 40. Combination Sum II

   Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

   Each number in candidates may only be used once in the combination.

   Note: The solution set must not contain duplicate combinations.
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        unordered_map<int, vector<vector<int>>> memo;

        res = memorizedCombSumTrace(candidates, target, memo);

        return res;
    }

    vector<vector<int>> memorizedCombSumTrace(vector<int>& candidates, int target, unordered_map<int, vector<vector<int>>>& memo) {
        vector<vector<int>> res;
        set<vector<int>> uniqueValidCombs;

        // Filter out the case that the sum of all candidates is less than the target.
        int sum = accumulate(candidates.begin(), candidates.end(), 0);
        if (sum < target) {
            return res;
        }
        else if (sum == target) {
            res.push_back(candidates);
            memo[target] = res;
            return res;
        }

        // Bottom Case
        if (1 == candidates.size()) {
            if (target == candidates[0]) {
                res.push_back({target});
                memo[target] = res;
            }

            // Return empty array if no valid combination of numbers found in the candidates.
            return res;
        }

        // Backtracking
        for (auto iter_o = candidates.begin(); iter_o != candidates.end(); ++iter_o) {
            // Filter out candidates that are too large.
            if (*iter_o > target) {
                continue;
            }
            else if (target == *iter_o) {
                uniqueValidCombs.insert(vector<int>({*iter_o}));
                continue;
            }

            vector<vector<int>> validSubCombs;
            if (memo[target - *iter_o].size() > 0) {
                validSubCombs = memo[target - *iter_o];
            }
            else {
                vector<int> lefts;
                lefts.insert(lefts.end(), candidates.begin(), iter_o);
                lefts.insert(lefts.end(), iter_o + 1, candidates.end());
                //assert(lefts.size() == candidates.size() - 1);

                validSubCombs = memorizedCombSumTrace(lefts, target - *iter_o, memo);
            }
            if (validSubCombs.size() > 0) {
                for (auto iter_i = validSubCombs.begin(); iter_i != validSubCombs.end(); ++iter_i) {
                    vector<int> validComb = *iter_i;

                    // Check if the valid candidates in the sub-combination already contains current candidate.
                    // i.e., there is no more number with the same value counting those in the sub-combination.
                    if (count(candidates.begin(), candidates.end(), *iter_o) > count(validComb.begin(), validComb.end(), *iter_o)) {
                        validComb.push_back(*iter_o);
                        
                        sort(validComb.begin(), validComb.end());
                        uniqueValidCombs.insert(validComb);
                    }
                }
            }
        }

        for (auto iter = uniqueValidCombs.begin(); iter != uniqueValidCombs.end(); ++iter) {
            res.push_back(*iter);
        }

        memo[target] = res;
        return res;
    }
};