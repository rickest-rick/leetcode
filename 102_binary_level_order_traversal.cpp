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
     * Given a binary tree, return the level order traversal of its nodes' values.
     * (ie, from left to right, level by level).
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> level_order;
        int level_size = 1; // number of elements of the current level
        int new_level_size; // number of elements of the next level
        queue<TreeNode*> level_queue;
        level_queue.emplace(root);
        // as long as nodes are left
        while (!level_queue.empty()) {
            new_level_size = 0;
            vector<int> level(level_size);
            // for the size of elements of the next level
            for (int i = 0; i < level_size; i++) {
                TreeNode* current = level_queue.front();
                level_queue.pop();
                // append them to the next level
                level[i] = current->val;
                // append every non null child to the level_queue and count
                if (current->left) {
                    level_queue.emplace(current->left);
                    new_level_size++;
                }
                if (current->right) {
                    level_queue.emplace(current->right);
                    new_level_size++;
                }
            }
            // append level to output
            level_order.emplace_back(level);
            level_size = new_level_size;
        }
        return level_order;
    }
};
