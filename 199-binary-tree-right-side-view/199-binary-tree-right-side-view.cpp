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
    void f(TreeNode* root, int level, vector<int> &ans) {
        if(!root) return;
        
        // if visiting the level for first time
        // thats the leftmost node for that level
        if(ans.size() == level) ans.push_back(root->val);
        
        f(root->right, level+1, ans);
        f(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        f(root, 0, ans);
        return ans;
    }
};