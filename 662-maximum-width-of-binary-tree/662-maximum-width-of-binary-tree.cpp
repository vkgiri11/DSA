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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
    
        long long maxWidth = 0;
        // Node, index
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();
            // taking the min index at every level
            long long minIndex = q.front().second;
            long long firstIndex, lastIndex;

            for(int i = 0; i < size; i++) {
                // modifying the index for every node
                long long currIndex = q.front().second - minIndex;

                TreeNode *node = q.front().first;
                q.pop();

                if(i == 0) firstIndex = currIndex;
                if(i == size-1) lastIndex = currIndex;

                if(node->left) q.push({node->left, 2*currIndex + 1});
                if(node->right) q.push({node->right, 2*currIndex + 2});
            }
            maxWidth = max(maxWidth, lastIndex - firstIndex + 1);
        }

        return (int)maxWidth;
    }
};