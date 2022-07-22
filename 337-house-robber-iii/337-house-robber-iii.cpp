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
    int f(TreeNode* root, unordered_map<TreeNode*, int> &map) {
        if(root == NULL) return 0;
        
        if(map.find(root) != map.end()) return map[root];
        
        int ans = 0;
        
        if(root->left != NULL)
            ans += f(root->left->left, map) + f(root->left->right, map);
        
        if(root->right != NULL)
            ans += f(root->right->left, map) + f(root->right->right, map);
        
        // there are two cases, one to rob the root or not
        
        // f(root->left) + f (root->right) : case if root is not robbed
        // root->val + ans : if root is robbed, ans stores the value 
        // from left and right grandchild of root. Add this to root->val
        ans = max(root->val + ans, f(root->left, map) + f (root->right, map));
        
        return map[root] = ans;
    }
    int rob(TreeNode* root) {
        // node, max value robbed at this node
        unordered_map<TreeNode*, int> map;
        return f(root, map);
    }
};