/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool inor(Node *r1,Node *r2){
        if(!r1 || !r2)return r1==r2;
        return r1->data==r2->data && inor(r1->right,r2->left) && inor(r1->left,r2->right);
    }
    bool isSymmetric(struct Node* root)
    {
        if(!root)return 1;
	    return inor(root->left,root->right);
    }
};
