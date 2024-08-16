//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    int f(int n,int a,int b,int c,vector<int>&dp,int s){
        if(s==n)return 0;
        if(s>n)return -1e5;
        if(dp[s]!=-1)return dp[s];
        int ff=0,ss=0,l=0;
        ff=f(n,a,b,c,dp,s+a)+1;
        ss=f(n,a,b,c,dp,s+b)+1;
        l=f(n,a,b,c,dp,s+c)+1;
        return dp[s]=max({ff,ss,l});
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        int t=f(n,x,y,z,dp,0);
        return t<0?0:t;
    }
};



//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends