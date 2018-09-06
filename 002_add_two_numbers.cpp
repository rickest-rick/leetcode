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
        
        int digit = 0, carryover = 0;
        int x = 0, y = 0;
        // iterate over the two lists until you reach the end of the longest
        while (l1 != NULL || l2 != NULL ){
            x = (l1 != NULL) ? l1->val : 0;
            y = (l2 != NULL) ? l2->val : 0;
        
            digit = x + y + carryover;
            // sum might result in carryover
            carryover = digit / 10;
            digit %= 10;
            
            // build new node for this digit and update current node
            current->next = new ListNode(digit);
            current = current->next;
            
            // go to the next node if there is one
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        // append new node if carryover results in number with more digits
        if (carryover > 0){
            current->next = new ListNode(carryover);
        }
        return head.next;
    }
};
