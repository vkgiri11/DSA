// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node *buildTreeHelper(int preorder[], int preStart, int preEnd,
        int inorder[], int inStart, int inEnd, map<int, int> &inorderMap) {
        
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        // the first elem of preorder is root. Making tree node
        Node *root = new Node(preorder[preStart]);
        
        // finding the index of root in inOrder array
        int inRoot = inorderMap[root->data];
        // num of elements present in left subtree
        int numsElem = inRoot - inStart;
        
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsElem,
                                    inorder, inStart, inRoot - 1, inorderMap);
        
        root->right = buildTreeHelper(preorder, preStart + 1 + numsElem, preEnd,
                                     inorder, inRoot + 1, inEnd, inorderMap);
        
        return root;
    }
    Node* buildTree(int inorder[],int preorder[], int n) {
        // elements -> index for inorder
        map<int, int> inorderMap;
        
        for(int i = 0; i < n; i++) inorderMap[inorder[i]] = i;
        
        Node *root = buildTreeHelper(preorder, 0, n-1,
                                              inorder, 0, n-1, inorderMap);
        
        return root;
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
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends