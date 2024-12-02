//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            int n=txt.size();
            int pp=pat.size();
            // string pt;
            if(txt.find(pat)>=n)return {};
            vector<int>ans;
            for(int i=0;i<n-pp+1;i++){
                if(txt[i]==pat[0]){
                    if(txt.substr(i,pp)==pat)ans.push_back(i);
                    // cout<<txt.substr(i,pp);
                }
                
            }
            return ans;
        }
     
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends