//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool valid (vector<int>&placed){
        int c1= placed.size(), r1= placed[c1-1];
        for (int i=0; i<c1-1; i++){
            int c2= i+1, r2= placed[i];
            if (r1==r2 || c1==c2 || abs(r1-r2)==abs(c1-c2)) 
                return false;
        }
        return true;
    }
    
    void recPlaceQueen(vector<vector<int>>&res, vector<int>&placed,int n){
        
        int c= placed.size()+1;
        if (c>n){
            res.push_back(placed);
            return;
        }
        for (int r=1; r<=n; r++){
            placed.push_back(r);
            if (valid(placed))
                recPlaceQueen(res,placed,n);
            placed.pop_back();
        }
    }
    
    vector<vector<int>>nQueen(int n) {
        vector<vector<int>>res;
        vector<int>placed;
        recPlaceQueen(res,placed,n);
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends