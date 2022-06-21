// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    struct Node {
        int data;
        Node *left, *right;
    };
    Node* newNode(int item) {
        Node* temp = new Node;
        temp->data = item;
        temp->left = temp->right = NULL;
     
        return temp;
    }
    
    Node *insert(Node* node, int key, Node *&succ) {
        // if node is NULL, this is the root of BST
        if(!node) return node = newNode(key);
        
        // If key is smaller than root's key, go to left
        // subtree and set successor as current node
        if(key < node->data) {
            succ = node;
            node->left = insert(node->left, key, succ);
        }
        
        // go to right subtree
        else if(key >= node->data) {
            node->right = insert(node->right, key, succ);
        }
        
        return node;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node *root = NULL;
        
        for(int i = n-1; i >= 0; i--) {
            Node *succ = NULL;
            
            // insert current element into BST and
            // find its inorder successor
            root = insert(root, arr[i], succ);
            
            // replace element by its inorder
            // successor in BST
            if (succ) arr[i] = succ->data;
            // No inorder successor
            else arr[i] = -1;
        }
        
        return arr;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends