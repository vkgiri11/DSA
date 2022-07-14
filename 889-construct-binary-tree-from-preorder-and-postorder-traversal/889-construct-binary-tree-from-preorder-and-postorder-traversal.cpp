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
    int findLeftSubRootInPost(int leftSubTreeVal, vector<int> &post, int postStart, int postEnd) {
        for(int i = postStart; i <= postEnd; i++) {
            if(post[i] == leftSubTreeVal) return i;
        }
        
        return -1;
    }
    TreeNode* treeBuilder(vector<int>& pre, int preStart, int preEnd, 
                          vector<int>& post, int postStart, int postEnd) {
        
        if(preStart > preEnd) return NULL;
        
        // if only one node, that is root
        if(preStart == preEnd) return new TreeNode(pre[preStart]);
        
        // root of the tree
        TreeNode *root = new TreeNode(pre[preStart]);
        
        // locate left subtree
        int leftSubStartInPre = preStart + 1;
        int leftSubRootInPost = findLeftSubRootInPost(pre[leftSubStartInPre], post, postStart, postEnd);
        int leftSubEndInPre = leftSubStartInPre + (leftSubRootInPost - postStart);
        
        TreeNode *leftSubRoot = treeBuilder(pre, leftSubStartInPre, leftSubEndInPre,
                                   post, postStart, leftSubRootInPost);
        
        TreeNode *rightSubRoot = treeBuilder(pre, leftSubEndInPre + 1, preEnd,
                                    post, leftSubRootInPost + 1, postEnd - 1);
        
        root->left = leftSubRoot;
        root->right = rightSubRoot;
        
        return root;       
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return treeBuilder(preorder, 0, preorder.size()-1,postorder, 0, postorder.size()-1);
    }
};