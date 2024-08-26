//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int n,m;
    int dp[201][201];
    bool help(int i,int j,string& pattern,string& str){
        if(i==n && j==m)return true;
        if(i>n || j>m)return false;
        bool ans=false;
        // cout<<i<<" "<<j<<"\n";
        if(dp[i][j]!=-1)return dp[i][j];
        if(pattern[i]==str[j]){
            ans=help(i+1,j+1,pattern,str);
            if(ans)return dp[i][j]=ans;
        }
        if(pattern[i]=='*'){
            ans|=help(i+1,j,pattern,str);
            if(ans)return dp[i][j]=ans;
            ans|=help(i,j+1,pattern,str);
            if(ans)return dp[i][j]=ans;
            ans|=help(i+1,j+1,pattern,str);
        }
        if(pattern[i]=='?')ans|=help(i+1,j+1,pattern,str);
        
        return dp[i][j]=ans;
    }
    int wildCard(string pattern, string str) {
        n=pattern.size();
        m=str.size();
        memset(dp,-1,sizeof(dp));
        return help(0,0,pattern,str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends