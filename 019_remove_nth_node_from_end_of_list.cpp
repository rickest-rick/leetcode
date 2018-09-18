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
     * Given a linked list, remove the n-th node from the end of list and return its head.
     * Example:
     * Given linked list: 1->2->3->4->5, and n = 2.
     * After removing the second node from the end, the linked list becomes 1->2->3->5.
     *
     * Note:
     * Given n will always be valid.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // construct new dummy node in front of the head
        ListNode start(0);
        start.next = head;
        
        ListNode* current = head;
        // skip n elements
        for (int i = 0; i < n; i++) {
            current = current->next;
        }
        ListNode* prev = &start;
        // follow current and prev until the end of current is reached, prefix will be n+1 steps behind
        while(current) {
            current = current->next;
            prev = prev->next;
        }
        // delete n-th node from the back
        prev->next = prev->next->next;
        return start.next;
    }
};
