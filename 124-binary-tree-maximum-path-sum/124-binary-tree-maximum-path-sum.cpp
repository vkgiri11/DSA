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
    int maxPathDown(TreeNode * root, int &maxAns) {
        if(root == NULL) return 0;

        // Ignore negative values, return 0 if negative value
        int leftSum = max(0, maxPathDown(root->left, maxAns));
        int rightSum = max(0, maxPathDown(root->right, maxAns));

        maxAns = max(maxAns, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxAns = INT_MIN;
        maxPathDown(root, maxAns);
        return maxAns;        
    }
};