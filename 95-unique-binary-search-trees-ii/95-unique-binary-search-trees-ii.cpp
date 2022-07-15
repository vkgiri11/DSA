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
    vector<TreeNode*> f(int start, int end) {
        if(start > end) return {NULL};
        
        // left subtree list - nodes in left subtree
        // right subtree list - nodes in right subtree
        vector<TreeNode*> lstList, rstList, ans; 
        
        for(int i = start; i <= end; i++) {
            // for 'i' to be root
            lstList = f(start, i-1);
            rstList = f(i+1, end);
            
            // storing all possible combinations of lstList and rstList
            for(auto leftNode: lstList) {
                for(auto rightNode: rstList) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        // tree node values from 1->n
        return f(1, n);
    }
};