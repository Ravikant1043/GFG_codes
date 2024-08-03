//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        vector<int> r(n,0),c(n,0);
        for(int i=0;i<n;i++){
            int p=0;
            int s=0;
            for(int j=0;j<n;j++)if(i!=j)p+=mat[i][j],s+=mat[j][i];
            r[i]=p;
            c[i]=s;
        }
        for(int i=0;i<n;i++){
            if(r[i]==0 && c[i]==n-1)return i;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends