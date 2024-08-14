//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        vector<vector<int>>mat(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s2.size();j++){
                if(s1[i]==s2[j]){
                    mat[i+1][j+1]=mat[i][j]+1;
                }
            }
        }
        int mm=INT_MIN;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)mm=max(mat[i][j],mm);
        }
        return mm;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends