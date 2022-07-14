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
    void inorder(TreeNode* root, TreeNode* &prev, TreeNode* &first, 
                 TreeNode* &middle, TreeNode* &last) {

        if(!root) return;

        inorder(root->left, prev, first, middle, last);

        // condition for violation
        if(prev != NULL && (prev->val > root->val)) {

            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if(first == NULL) {
                first = prev;
                middle = root;
            }

            // If this is second violation, mark this node as last
            else last = root;
        }

        // this node work is done, so mark it as previous 
        prev = root;

        inorder(root->right, prev, first, middle, last);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev, *first, *middle, *last;
        
        first = middle = last = NULL;
    
        // the first prev for a correct BST will have smallest value
        prev = new TreeNode(INT_MIN);

        inorder(root, prev, first, middle, last);

        // violating nodes are not adjacent
        if(first && last) swap(first->val, last->val); 
        // violating nodes are adjacent
        else if(first && middle) swap(first->val, middle->val); 

        return;
    }
};