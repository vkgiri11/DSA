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
    int f(TreeNode* root, unordered_map<TreeNode*, int> &dp) {
        if(!root) return 0;
        
        if(dp.count(root)) return dp[root];
        
        // there are two cases, one to rob the root or not
        // f(root->left) + f (root->right) : case if root is not robbed
        int dontRobRoot = f(root->left, dp) + f(root->right, dp);
        
        // if root is robbed then we can rob only the grandchilds of root
        int robRoot = root->val;
        
        if(root->left != NULL)
            robRoot += f(root->left->left, dp) + f(root->left->right, dp);
        
        if(root->right != NULL)
            robRoot += f(root->right->left, dp) + f(root->right->right, dp);
        
        return dp[root] = max(robRoot, dontRobRoot);
    }
    int rob(TreeNode* root) {
        // node, max value robbed at this node
        unordered_map<TreeNode*, int> dp;
        return f(root, dp);
    }
};