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
     * Given a binary tree, determine if it is a valid binary search tree (BST).
     * Input:
            2
           / \
          1   3
        Output: true

        Example 2:
        
            5
           / \
          1   4
             / \
            3   6
        Output: false
     */
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MAX, LONG_MIN);
    }
    
    /**
     * Given a binary tree, check recursively if this tree is a valid BST.
     * @upper_bound : every value of this sub tree has to be smaller than upper_bound
     * @lower_bound : every value of this sub tree has to be larger than lower_bound
     */
    bool isValid(TreeNode* root, long upper_bound, long lower_bound) {
        if (!root) return true;
        if (root->val >= upper_bound || root->val <= lower_bound) return false;
        bool left_valid = isValid(root->left, root->val, lower_bound);
        bool right_valid = isValid(root->right, upper_bound, root->val);
        return left_valid && right_valid;
    }
};
