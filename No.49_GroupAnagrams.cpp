// Author:  Sheng (Raymond) Liao
// Date:    April 2023

/* 49. Group Anagrams

   Given an array of strings strs, group the anagrams together. You can return the answer in any order.

   An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
   typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagramsMap;

        for (auto iter = strs.begin(); iter != strs.end(); ++iter) {
            string countAndSay = countCharAndSay(*iter);
            anagramsMap[countAndSay].push_back(*iter);
        }

        for (auto map_iter = anagramsMap.begin(); map_iter != anagramsMap.end(); ++map_iter) {
            vector<string> anagramsGroup;
            for (auto arr_iter = map_iter->second.begin(); arr_iter != map_iter->second.end(); ++arr_iter) {
                anagramsGroup.push_back(*arr_iter);
            }

            res.push_back(anagramsGroup);
        }

        return res;
    }

private:
    string countCharAndSay(const string& str) {
        string countAndSay;
        map<char, int> charCountMap;

        for (int i = 0; i < str.size(); ++i) {
            charCountMap[str[i]]++;
        }

        for (auto iter = charCountMap.begin(); iter != charCountMap.end(); ++iter) {
            countAndSay += (to_string(iter->second) + iter->first);
        }

        return countAndSay;
    }
};