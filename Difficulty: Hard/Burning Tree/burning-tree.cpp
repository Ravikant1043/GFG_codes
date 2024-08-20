//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
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
class Solution {
  public:
    Node* help(Node*root,int tar){
        if(!root)return NULL;
        if(root->data==tar)return root;
        Node* l=help(root->left,tar);
        Node* r=help(root->right,tar);
        if(l==NULL)return r;
        return l;
    }
    unordered_map<Node*,Node*> mp;
    void parent(Node* root){
        if(!root)return;
        if(root->left)mp[root->left]=root;
        if(root->right)mp[root->right]=root;
        parent(root->left);
        parent(root->right);
    }
    int minTime(Node* root, int target) 
    {
        Node* t=help(root,target);
        mp[root]=NULL;
        parent(root);
        int ans=0;
        queue<pair<int,Node*>> q;
        t->data=-1*t->data;
        q.push({0,t});
        while(q.size()){
            auto it=q.front();
            q.pop();
            int val=it.first;
            Node* n=it.second;
            vector<Node*> tp = {n->left,n->right,mp[n]};
            for(auto i:tp){
                if(i && i->data>0){
                    q.push({val+1,i});
                    i->data=-1*i->data;
                    ans=max(ans,val+1);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends