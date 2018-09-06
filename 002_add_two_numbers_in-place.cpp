/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    /**
    * helper function which returns a pointer at the head of the longer node
    */
    ListNode* longestList(ListNode* l1, ListNode* l2) {
        ListNode* currentL1 = l1;
        ListNode* currentL2 = l2;
        // iterate over both lists until you reach the end of one of them
        while (currentL1->next && currentL2->next) {
            currentL1 = currentL1->next;
            currentL2 = currentL2->next;
        }
        if (!currentL2->next) {
            return l1;
        }
        else return l2;
    }
    
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
        // use the nodes of the longer list for the result
        ListNode* head = longestList(l1, l2);
        ListNode* currentResultNode = head;
        ListNode* currentInputNode = (head == l1) ? l2 : l1;
        ListNode* predecessor = head;
        
        int digit = 0, carryover = 0;
        // iterate over the two lists until you reach the end of the longest
        while (currentResultNode){
            int x = currentResultNode->val;
            int y = (currentInputNode) ? currentInputNode->val : 0;
        
            digit = x + y + carryover;
            // sum might result in carryover
            carryover = digit / 10;
            digit %= 10;
            
            // update val of current result node
            currentResultNode->val = digit;
            
            // update predecessor only if another node remains; if not, this
            // node will be predecessor to the new node in case of a carryover
            if (predecessor->next) predecessor = predecessor->next;
            // go to the next node
            currentResultNode = currentResultNode->next;
            if(currentInputNode) currentInputNode = currentInputNode->next;
        }
        // append new node if carryover results in number with more digits
        if (carryover > 0){
            ListNode* tail = new ListNode(carryover);
            predecessor->next = tail;
        }
        return head;
    }
};
