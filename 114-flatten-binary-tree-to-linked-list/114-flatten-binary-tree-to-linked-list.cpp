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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        TreeNode *curr = root;
        
        while(curr)  {
            if(curr->left) {
                TreeNode *prev = curr->left;
                
                // prev points to the last node in the left subtree;
                while(prev->right) prev = prev->right;
                
                prev->right = curr->right;
                
                // in the Linked List, curr's next is left node of curr in tree
                curr->right = curr->left;
                
                curr->left = NULL;
            }
            
            // in tree, this means moving to the left subtree
            // but since new threads have been made the left node is at right
            curr = curr->right;
        }
    }
};