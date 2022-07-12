/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void trackParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // node->parent
        unordered_map<TreeNode*, TreeNode*> parent;
        trackParent(root, parent);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        
        int currDistance = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            if(currDistance == k) break;
            
            currDistance++;
            
            for(int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                
                if(parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};