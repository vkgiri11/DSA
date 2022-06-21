// { Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/
/* root node can be in the range [1, ∞]  
left sub-tree can have the value in the range [1, val-1] and 
right sub-tree the value in range [val+1, ∞]. 
traverse recursively and when min and max value of range coincided 
it means that we cannot add any node further in the tree. 
Hence we encounter a dead end.*/
bool f(Node *root, int min, int max) {
    // if the root is null or the recursion moves
    // after leaf node it will return false
    // i.e no dead end.
    if(root == NULL) return false;
    
    // if this occurs means dead end is present.
    if(min == max) return true;
    
    return f(root->left, min, root->data - 1) 
            || f(root->right, root->data + 1, max);
}
bool isDeadEnd(Node *root) {
    return f(root, 1, 1e9);
}