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
        stack<ListNode*> s;
        ListNode* current = head;
        // push each node on a stack until the end is reached
        while (current) {
            s.push(current);
            current = current->next;
        }
        // pop the stack n times and save the element in front of the element to be deleted
        for (int i = 0; i < n; i++) s.pop();
        if (s.size() == 0) return head->next;
        current = s.top();
        current->next = current->next->next;
        return head;
    }
};
