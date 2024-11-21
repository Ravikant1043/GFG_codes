//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int help(int i,int &n,vector<int>&prices,int b,vector<vector<int>>&dp){
        if(i>=n)return 0;
        int t=0,nt=0;
        if(dp[i][b]!=-1)return dp[i][b];
        if(b){
            t=help(i+1,n,prices,0,dp)-prices[i];
        }
        else{
            t=help(i+1,n,prices,1,dp)+prices[i];
        }
        nt=help(i+1,n,prices,b,dp);
        
        return dp[i][b]=max(t,nt);
    }
    int maximumProfit(vector<int> &prices) {
        int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(0,n,prices,1,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends