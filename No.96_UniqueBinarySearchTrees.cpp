// Author:  Sheng (Raymond) Liao
// Date:    April 2023

/* 96. Unique Binary Search Trees

   Given an integer n, return the number of structurally unique BST's (binary search trees) 
   which has exactly n nodes of unique values from 1 to n.
*/

class Solution {
public:
    int numTrees(int n) {
        pair<int, int> nodes(1, n);
        map<string, int> memo;

        // Backtracking
        int res = placeChildNodes(nodes, memo);
        return res;
    }

private:
    int placeChildNodes(pair<int,int> nodes, map<string, int>& memo) {
        /**
          * "nodes" denotes sorted consecutive numbers to be used to form a BST.
          * Return the number of ways to place nodes to form a BST.
          */

        // there is only one way to form a BST if only one or no node presented.
        int count = nodes.second - nodes.first + 1;
        if (count < 2) {
            return 1;
        }

        // If we already calculate the ways for placing consecutive numbers to form a BST, just retrieve the answer.
        string rangeStr = std::to_string(nodes.first) + std::to_string(nodes.second);
        if (memo.find(rangeStr) != memo.end()) {
            return memo[rangeStr];
        }

        int ways = 0;

        // Place the consecutive numbers to form BSTs.
        for (int num = nodes.first; num <= nodes.second; ++num) {
            // Place the left children.
            int leftWays = placeChildNodes(pair<int, int>(nodes.first, num - 1), memo);

            // Place the right children.
            int rightWays = placeChildNodes(pair<int, int>(num + 1, nodes.second), memo);

            ways += leftWays * rightWays;
        }

        memo[rangeStr] = ways;
        return ways;
    }
};