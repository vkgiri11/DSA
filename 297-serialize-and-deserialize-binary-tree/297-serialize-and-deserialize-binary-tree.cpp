/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();

            if(curr == NULL) ans.append("#,");
            else ans.append(to_string(curr->val)+',');

            if(curr != NULL) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(!data.size()) return NULL;

        stringstream ss(data);
        string ans;
        // stringstream, node val in string, delimiter
        getline(ss, ans, ',');
        // ans contains the part of string just before ','

        TreeNode* root = new TreeNode(stoi(ans));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // moves to the next val
            getline(ss, ans, ',');
            if(ans == "#") curr->left = NULL;
            else {
                TreeNode* leftNode = new TreeNode(stoi(ans));
                curr->left = leftNode;
                q.push(leftNode);
            }

            // moves to the next val
            getline(ss, ans, ',');
            if(ans == "#") curr->right = NULL;
            else {
                TreeNode* rightNode = new TreeNode(stoi(ans));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));