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
    TreeNode *buildTreeHelper(vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorderMap) {

        if(preStart > preEnd || inStart > inEnd) return NULL;

        // the first elem of preorder is root. Making tree node
        TreeNode* root = new TreeNode(preorder[preStart]);

        // finding the index of root in inOrder array
        int inRoot = inorderMap[root->val];
        // num of elements present in left subtree
        int numsElem = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsElem,
                                    inorder, inStart, inRoot - 1, inorderMap);

        root->right = buildTreeHelper(preorder, preStart + 1 + numsElem, preEnd,
                                     inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // elements -> index for inorder
        map<int, int> inorderMap;

        for(int i = 0; i < inorder.size(); i++) inorderMap[inorder[i]] = i;
        
        TreeNode *root = buildTreeHelper(preorder, 0, preorder.size()-1,
                                              inorder, 0, inorder.size()-1, inorderMap);

        return root;
    }
};