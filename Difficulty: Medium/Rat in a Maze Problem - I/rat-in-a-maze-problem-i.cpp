//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void find(int i,int j,vector<vector<int>>&m,string hans,
    vector<vector<int>>&help,int &n,vector<string>&ans){
        if(i<0 ||j<0 || i>=n || j>=n || m[i][j]==0 || help[i][j]==1)return ;
        if(i==n-1 && j==n-1){
            ans.push_back(hans);
            return ;
        }
        
        help[i][j]=1;
        
        find(i+1,j,m,hans+"D",help,n,ans);
        find(i,j+1,m,hans+"R",help,n,ans);
        find(i-1,j,m,hans+"U",help,n,ans);
        find(i,j-1,m,hans+"L",help,n,ans);
        
        help[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
       vector<string>ans;
        int n=mat.size();
        vector<vector<int>>help(n,vector<int>(n,0));
        find(0,0,mat,"",help,n,ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends