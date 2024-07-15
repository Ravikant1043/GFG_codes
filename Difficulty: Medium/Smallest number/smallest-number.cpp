//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string help(int s,int d,vector<vector<string>> &dp){
        if(d==0){
            if(s!=0){
                return "9999999";
            }
            else return "";
        }
        if(dp[s][d]!="-1")return dp[s][d];
        int i = (d==1?1:0);
        string ans="9999999";
        for(;i<=9;i++){
            if(s-i>=0)
            ans=min(ans,help(s-i,d-1,dp)+to_string(i));
        }
        return dp[s][d]=ans;
    }
    string smallestNumber(int s, int d) {
        vector<vector<string>> dp(s+1,vector<string> (d+1,"-1"));
        string ans= help(s,d,dp);
        if(ans=="9999999"||ans=="-1")return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends