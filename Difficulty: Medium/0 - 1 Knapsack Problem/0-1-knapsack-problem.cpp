//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int help(int w,vector<int>& wt,vector<int>& val,int i,int n,vector<vector<int>> &ans){
        if(i>=n || w==0)return 0;
        if(ans[i][w]!=-1)return ans[i][w];
        int p=0,np=0;
        if(wt[i]<=w){
            p=help(w-wt[i],wt,val,i+1,n,ans)+val[i];
        }
        np=help(w,wt,val,i+1,n,ans);
        return ans[i][w] = max(np,p);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=val.size();
        vector<vector<int>>ans(n+1,vector<int>(W+1,-1));
        return help(W,wt,val,0,n,ans);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends