/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /** 
     * Given a binary tree, find its maximum depth. 
     * The maximum depth is the number of nodes along the longest path from 
     * the root node down to the farthest leaf node.
     * Note: A leaf is a node with no children.
     */
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // depth is max of left and right subtree + 1 for the root
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
