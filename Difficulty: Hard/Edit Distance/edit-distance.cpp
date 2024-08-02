//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int help(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return help(i-1,j-1,s,t,dp);
        }
        int r=0,rm=0,in=0;
        in=1+help(i-1,j,s,t,dp);
        r=1+help(i,j-1,s,t,dp);
        rm=help(i-1,j-1,s,t,dp)+1;
        return dp[i][j]=min({in,r,rm});
    }
    int editDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return help(n-1,m-1,s,t,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends