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
    void f(TreeNode* root, long long int targetSum, int &ways) {
        if(!root) return;
        
        if(targetSum == root->val) ways++;
        
        f(root->left, targetSum - root->val, ways);
        f(root->right, targetSum - root->val, ways);
    }
    void pathSumHelper(TreeNode* root, int targetSum, int &ways) {
        if(root) {
            f(root, targetSum, ways);
            pathSumHelper(root->left, targetSum, ways);
            pathSumHelper(root->right, targetSum, ways);
        }
        
        return;
    }
    int pathSum(TreeNode* root, int targetSum) { 
        int ways = 0;
        pathSumHelper(root, targetSum, ways);
        return ways;
    }
};