/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // O(1) : space, O(n) : time(visiting all nodes once)
    Node* connect(Node* root) {
        Node *levelStart = root;
        
        while(levelStart != NULL) {
            Node *curr = levelStart;
            
            while(curr != NULL) {
                // if curr left exists, right will also exists
                // since this is perfect binary tree
                if(curr->left) {
                    // the left child next will point to right child
                    curr->left->next = curr->right;
                    
                    // the curr has some next, 
                    // the left child of curr will point to left child of curr->next
                    if(curr->next) curr->right->next = curr->next->left;
                }
                
                // move to the next node in same level
                curr = curr->next;
            }
            
            // move to next Level
            levelStart = levelStart->left;
        }
        
        return root;
        
    }
};

/*
    // O(n) : both space and time
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto currNode = q.front();
                q.pop();
                
                // for the last node in a level, next points to NULL
                if(i == size-1) currNode->next = NULL;
                // else it points to the front of queue, which is its immediate right
                else currNode->next = q.front();
                
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
             
            }
        }
        
        return root;
    }
*/