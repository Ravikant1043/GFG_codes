//{ Driver Code Starts
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
    Node* constru(int in[],
    int po[],int ini,int inj,int poi,int poj,unordered_map<int,int>&mp){
        if(ini>inj || poi>poj)return NULL;
        Node* t=new Node(po[poi]);
        int k=mp[po[poi]];
        int r=k-ini;
        t->left=constru(in,po,ini,k-1,poi+1,poi+r,mp);
        t->right=constru(in,po,k+1,inj,poi+1+r,poj,mp);
        return t;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[in[i]]=i;
        return constru(in,pre,0,n-1,0,n-1,mp);   
    }
};

//{ Driver Code Starts.
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