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
    * You are given two non-empty linked lists representing two 
    * non-negative integers. The digits are stored in reverse order 
    * and each of their nodes contain a single digit. Add the two 
    * numbers and return it as a linked list.
    *
    * You may assume the two numbers do not contain any leading zero, 
    * except the number 0 itself.
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* current = &head;
        ListNode* nodeL1 = l1;
        ListNode* nodeL2 = l2;
        
        int digit = 0, carryover = 0;
        int x = 0, y = 0;
        // iterate over the two lists until you reach the end of the longest
        while (nodeL1 != NULL || nodeL2 != NULL ){
            x = (nodeL1 != NULL) ? nodeL1->val : 0;
            y = (nodeL2 != NULL) ? nodeL2->val : 0;
        
            digit = x + y + carryover;
            // sum might result in carryover
            carryover = digit / 10;
            digit %= 10;
            
            // build new node for this digit and update current node
            current->next = new ListNode(digit);
            current = current->next;
            
            // go to the next node if there is one
            if (nodeL1 != NULL) nodeL1 = nodeL1->next;
            if (nodeL2 != NULL) nodeL2 = nodeL2->next;
        }
        // append new node if carryover results in number with more digits
        if (carryover > 0){
            ListNode* tail = new ListNode(carryover);
            current->next = tail;
        }
        return head.next;
    }
};
