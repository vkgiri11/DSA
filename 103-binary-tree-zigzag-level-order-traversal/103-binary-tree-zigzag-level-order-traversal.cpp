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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> currLevel(size);
            
            for(int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                
                // if true insert from start else fill from end
                int index = leftToRight ? i : (size-1-i);
                currLevel[index] = node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            // switch the value after every level
            leftToRight = !leftToRight;
            ans.push_back(currLevel);
        }
        
        return ans;
    }
};