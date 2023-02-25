// Author:  Sheng (Raymond) Liao
// Date:    February 2023

/* 39. Combination Sum

   Given an array of distinct integers candidates and a target integer target, 
   return a list of all unique combinations of candidates where the chosen numbers sum to target. 
   You may return the combinations in any order.

   The same number may be chosen from candidates an unlimited number of times. 
   Two combinations are unique if the frequency of at least one of the chosen numbers is different.

   The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());

        vector<int> candidatesChosen;
        int curCandidateId = 0, preCandidateLastPos = 0;
        int sum = 0;

        while (1) {
            while (sum < target) {
                int num = candidates[curCandidateId];
                sum += num;
                candidatesChosen.push_back(num);

                if (sum == target) {
                    res.push_back(candidatesChosen);
                }
            }
            sum -= candidatesChosen.back();
            candidatesChosen.pop_back();
            

            // Bottom Case
            if (0 == candidatesChosen.size()) {
                break;
            }
            int c = candidatesChosen[0];
            if (c == candidates[candidates.size() - 1] && sum + c >= target) {
                break;
            }

            // Try the next larger candidate.
            if (curCandidateId == candidates.size() - 1) {
                candidatesChosen.erase(candidatesChosen.begin() + preCandidateLastPos + 1, candidatesChosen.end());

                curCandidateId = (find(candidates.begin(), candidates.end(), candidatesChosen.back()) - candidates.begin()) + 1;

                candidatesChosen.pop_back();
                --preCandidateLastPos;

                sum = 0;
                for (int i = 0; i < candidatesChosen.size(); ++i) {
                    sum +=  candidatesChosen[i];
                }
            }
            else {
                curCandidateId = (find(candidates.begin(), candidates.end(), candidatesChosen.back()) - candidates.begin()) + 1;

                sum -= candidatesChosen.back();
                candidatesChosen.pop_back();

                preCandidateLastPos = candidatesChosen.size() - 1;
            }

        }

        return res;
    }
};