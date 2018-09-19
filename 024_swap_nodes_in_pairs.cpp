/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** 
     * Given a linked list, swap every two adjacent nodes and return its head.
     * Example:
     * Given 1->2->3->4, you should return the list as 2->1->4->3.
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* current = &dummy;
        // as long as two or more nodes are behind the current ...
        while (current->next && current->next->next) {
            // ... swap these nodes
            ListNode* tmp = current->next;
            current->next = current->next->next;
            tmp->next = current->next->next;
            current->next->next = tmp;
            // continue with the next but one
            current = current->next->next;
        }
        return dummy.next;
    }
};
