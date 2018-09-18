/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct for comparison of ListNodes for a Min-Heap
struct compare {
    bool operator()(const ListNode* l1, const ListNode* l2) {
        return l1->val> l2->val;
    }
};
class Solution {
public:
    /**
     * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its 
     * complexity.
     *   Example:
     *   Input:
     *   [
     *     1->4->5,
     *     1->3->4,
     *     2->6
     *   ]
     *   Output: 1->1->2->3->4->4->5->6
     * Complexity: Let n be the number of elements total and k the number of linked lists. 
     * This algorithm has a complexity of O(n * log k), because n elements are added to and 
     * removed from the heap in total, but it contains not more than k elements at each time.
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        // add first element of each list to minHeap;
        for (auto l : lists) {
            if (l) minHeap.push(l);
        }
        // while the heap is not empty
        while (!minHeap.empty()) {
            // remove the list node with the smallest value from the heap and add it to the output
            tail->next = minHeap.top();
            tail = tail->next;
            minHeap.pop();
            // update the heap by adding the next element of the list whose element was removed
            if (tail->next) minHeap.push(tail->next);
        }
        return dummy.next;
    }
};
