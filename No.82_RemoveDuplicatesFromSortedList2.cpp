// Author:  Sheng (Raymond) Liao
// Date:    April 2023

/* 82. Remove Duplicates from Sorted List II

   Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
   leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curNode = head, *nodeToCheck = nullptr;
        int curDupVal = -101;

        if (nullptr == curNode) {
            return head;
        }

        // Find the first node with distinct value and make it the new head.
        while (nullptr != curNode->next && curNode->val == curNode->next->val) {
            curDupVal = curNode->val;
            curNode = curNode->next;

            while (nullptr != curNode && curDupVal == curNode->val) {
                curNode = curNode->next;
            }

            if (nullptr == curNode) {
                break;
            }
        }
        
        ListNode* newHead = curNode;
        // The original nodes may be all of the same value.
        if (nullptr == newHead) {
            return newHead;
        }

        // Delete all other nodes with duplciate values.
        while (nullptr != curNode->next && nullptr != curNode->next->next) {
            if (curNode->next->val == curNode->next->next->val) {
                curDupVal = curNode->next->val;
                nodeToCheck = curNode->next->next;

                while (nullptr != nodeToCheck && curDupVal == nodeToCheck->val) {
                    nodeToCheck = nodeToCheck->next;
                }

                curNode->next = nodeToCheck;
            }
            else {
                curNode = curNode->next;
            }
        }

        return newHead;
    }
};