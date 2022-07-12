/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int maxTillNow) {
        if(!node) return 0;
        
        int count = 0;
        
        if(node->val >= maxTillNow) {
            maxTillNow = node->val;
            count++;
        }
        
        count += dfs(node->left, maxTillNow) + dfs(node->right, maxTillNow);
        
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};