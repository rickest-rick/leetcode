/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     *  A linked list is given such that each node contains an additional 
     * random pointer which could point to any node in the list or null.
     * Return a deep copy of the list. 
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* currentNode = head;
        // interweave a new node after every old node
        // A -> A' -> B -> B' -> C -> C'
        do {
            RandomListNode* newNode = new RandomListNode(currentNode->label);
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            currentNode = newNode->next;
        } while(currentNode);
        // set the random pointers of new nodes to the node interweaved
        // behind the element the predecessor points to
        currentNode = head;
        do {
            if (currentNode->random) 
                currentNode->next->random = currentNode->random->next;
            else
                currentNode->next->random = NULL;
            currentNode = currentNode->next->next;
        } while(currentNode);        
        // split the interweaved list back to the old list and its copy
        RandomListNode* newHead = head->next;
        currentNode = head;
        RandomListNode* newNode = newHead;
        do {
            currentNode->next = currentNode->next->next;
            if (newNode->next) newNode->next = newNode->next->next;
            currentNode = currentNode->next;
            newNode = newNode->next;
        } while(currentNode);
        return newHead;
    }
};
