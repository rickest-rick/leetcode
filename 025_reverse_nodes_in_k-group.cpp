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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;
        stack<ListNode*> reverseStack;
        bool endReached = false;
        // as long as nodes are left ...
        while (current->next) {
            ListNode* behindCurrent = current->next;
            // ... push the next k nodes on a stack
            for (int i = 0; i < k; i++) {
                if (behindCurrent) {
                    reverseStack.push(behindCurrent);
                    behindCurrent = behindCurrent->next;
                } else {
                    endReached = true;
                    break;
                }
            }
            // stop if end of possible k groups was reached
            if (endReached) break;
            ListNode* successor = reverseStack.top()->next;
            // append all elements on the stack in reverse order to the current node
            while (!reverseStack.empty()) {
                current->next = reverseStack.top();
                reverseStack.pop();
                current = current->next;
            }
            // update next successor to next of former last element of k-group (was on 
            // top of stack)
            current->next = successor;
        }
        return dummy.next;
    }
};
