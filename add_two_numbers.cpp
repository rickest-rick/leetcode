// TWO WHILE LOOPS HAVE TO BE MERGED TO REDUCE REDUNDANT CODE

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
        
        int digit = 0, carryover = 0;
        bool firstEndReached = false, secondEndReached = false;
        // iterate over the two lists until you reach the end of one of them
        while (!(firstEndReached || secondEndReached)) {
            // add the current elements and possible carryover
            digit = currentResultNode->val + currentInputNode->val + carryover;
            
            // check if sum > 9 for next carryover
            if (digit > 9){
                carryover = 1;
                digit %= 10;
            }
            else { carryover = 0; }
            // save the digit in the current result node
            currentResultNode->val = digit;
            
            // go to the next digit
            if (currentResultNode->next) { currentResultNode = currentResultNode->next; }
            else {firstEndReached = true; }
            if (currentInputNode->next) { currentInputNode = currentInputNode->next; }
            else {secondEndReached = true; }
        }
        // if the end of the smaller number is reached, append the digits of the 
        // longer one and the carryover
        while (!(firstEndReached && secondEndReached)) {
            digit = currentResultNode->val + carryover;
            
            // check if sum > 9 for next carryover
            if (digit > 9){
                carryover = 1;
                digit %= 10;
            }
            else { carryover = 0; }
            
            currentResultNode->val = digit;
            if (currentResultNode->next) {
                currentResultNode = currentResultNode->next; 
            }
            else {
                firstEndReached = true;
                secondEndReached = true;
            }
        }
        // append new node if carryover results in number with more digits
        if (carryover > 0){
            ListNode* tail = new ListNode(carryover);
            currentResultNode->next = tail;
        }
        return head;
    }
};
