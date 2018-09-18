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
        size_t size = listSize(head);
        // return NULL, when last node is deleted
        if (size == 1) return NULL;
        // return list without head, if head is to be removed
        if (size == n) return head->next;
        
        ListNode* current = head;
        // skip to node in front of the node to be deleted
        for (int i = 0; i + 1 < size - n; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
private:
    size_t listSize(ListNode* head) {
        size_t size = 0;
        ListNode* current = head;
        while(current) {
            size++;
            current = current->next;
        }
        return size;
    }
};
