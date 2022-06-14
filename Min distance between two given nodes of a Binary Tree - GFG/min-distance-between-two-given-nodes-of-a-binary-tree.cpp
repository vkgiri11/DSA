// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    Node *findLca(Node* root, int n1, int n2){
        // if root is null/it matches with p or q -> return null/root 
        if(root == NULL || root->data == n1 || root->data == n2) 
            return root;
        
        Node* left = findLca(root->left, n1, n2);
        Node* right = findLca(root->right, n1, n2);
        
        if(left == NULL) return right;
        if(right == NULL) return left;
        // both returns some value, LCA found
        else return root;
    }
    int findDistHelper(Node* root, int nodeVal, int distance) {
        if(!root) return -1;
        
        if(root->data == nodeVal) return distance;
        
        int leftDist = findDistHelper(root->left, nodeVal, distance+1);
        // if found in left return no need to check in right
        if(leftDist != -1) return leftDist;
        // else check in right subtree
        return findDistHelper(root->right, nodeVal, distance+1);
    }
    int findDist(Node* root, int a, int b) {
        Node* lca = findLca(root, a, b);
        return findDistHelper(lca, a, 0) + findDistHelper(lca, b, 0);
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends